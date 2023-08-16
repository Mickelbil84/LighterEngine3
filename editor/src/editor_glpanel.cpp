#include "editor_glpanel.h"

BEGIN_EVENT_TABLE(LRE3wxOpenGLPanel, wxGLCanvas)
EVT_MOTION(LRE3wxOpenGLPanel::mouseMoved)
EVT_LEFT_DOWN(LRE3wxOpenGLPanel::mouseDown)
EVT_LEFT_UP(LRE3wxOpenGLPanel::mouseReleased)
EVT_RIGHT_DOWN(LRE3wxOpenGLPanel::rightClick)
EVT_LEAVE_WINDOW(LRE3wxOpenGLPanel::mouseLeftWindow)
EVT_SIZE(LRE3wxOpenGLPanel::resized)
EVT_KEY_DOWN(LRE3wxOpenGLPanel::keyPressed)
EVT_KEY_UP(LRE3wxOpenGLPanel::keyReleased)
EVT_MOUSEWHEEL(LRE3wxOpenGLPanel::mouseWheelMoved)
EVT_PAINT(LRE3wxOpenGLPanel::render)
END_EVENT_TABLE()


void LRE3wxOpenGLPanel::mouseMoved(wxMouseEvent& event) 
{
    event.Skip();
}
void LRE3wxOpenGLPanel::mouseDown(wxMouseEvent& event) 
{
    m_input.bLeftMouse = true;
    event.Skip();
}
void LRE3wxOpenGLPanel::mouseWheelMoved(wxMouseEvent& event) {event.Skip();}
void LRE3wxOpenGLPanel::mouseReleased(wxMouseEvent& event)
{
     m_input.bLeftMouse = false;
    event.Skip();
}
void LRE3wxOpenGLPanel::rightClick(wxMouseEvent& event) {event.Skip();}
void LRE3wxOpenGLPanel::mouseLeftWindow(wxMouseEvent& event) {event.Skip();}
void LRE3wxOpenGLPanel::keyPressed(wxKeyEvent& event) 
{
    m_input.keyboard[event.GetKeyCode()] = true;
}
void LRE3wxOpenGLPanel::keyReleased(wxKeyEvent& event) 
{
    m_input.keyboard[event.GetKeyCode()] = false;
}

 
LRE3wxOpenGLPanel::LRE3wxOpenGLPanel(wxFrame* parent, int* args) :
    wxGLCanvas(parent, wxID_ANY, args, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE)
{
    m_contextAttribs.CoreProfile().OGLVersion(4, 1).Robust().ResetIsolation().EndList();
	m_context = new wxGLContext(this, nullptr, &m_contextAttribs);
    wxGLCanvas::SetCurrent(*m_context);

    // To avoid flashing on MSW
    SetBackgroundStyle(wxBG_STYLE_CUSTOM);

    glewExperimental = true;
    glewInit();

    glEnable(GL_DEPTH_TEST);

    // ---------------------------
    //   Initialize keys
    // ---------------------------
    m_input.keyboard['W'] = false;
    m_input.keyboard['S'] = false;
    m_input.keyboard['A'] = false;
    m_input.keyboard['D'] = false;

    // ---------------------------
    //   Setup timer
    // ---------------------------
    m_timer.Bind(wxEVT_TIMER, &LRE3wxOpenGLPanel::update, this);
    m_timer.Start(5);

    m_prevTime = m_currTime = wxGetLocalTimeMillis();
    m_lastMouse = wxGetMousePosition();

}
 
void LRE3wxOpenGLPanel::update(wxTimerEvent& evt)
{
    wxPoint newPos = wxGetMousePosition();
    wxPoint relPos = ScreenToClient(newPos);
    m_input.mouseX = relPos.x;
    m_input.mouseY = relPos.y;
    m_input.screenWidth = getWidth();
    m_input.screenHeight = getHeight();
    m_input.relativeMouseX = ((float) m_input.mouseX  / (float) m_input.screenWidth - 0.5f) * 2.f;
    m_input.relativeMouseY = -((float) m_input.mouseY  / (float) m_input.screenHeight - 0.5f) * 2.f;
    m_input.xrel = newPos.x - m_lastMouse.x;
    m_input.yrel = newPos.y - m_lastMouse.y;
    m_lastMouse = newPos;

    if (GetRect().Contains(ScreenToClient(newPos)))
    {
        // Register mouse click events only inside the viewport
        wxMouseState mouseState = wxGetMouseState();
        m_input.bLeftMouse = mouseState.LeftIsDown();
        m_input.bRightMouse = mouseState.RightIsDown();
    }
    else
    {
        m_input.bLeftMouse = false;
        m_input.bRightMouse = false;
    }

    m_currTime = wxGetLocalTimeMillis();
    wxLongLong delta = m_currTime - m_prevTime;
    m_deltaTime = (float)delta.ToDouble() / 1000.0;
    m_prevTime = m_currTime;

    m_editor->HandleInput(m_input);
    m_editor->Update(m_deltaTime);
    Refresh();
}

LRE3wxOpenGLPanel::~LRE3wxOpenGLPanel()
{
	delete m_context;
}

void LRE3wxOpenGLPanel::resized(wxSizeEvent& evt)
{
//	wxGLCanvas::OnSize(evt);
	
    Refresh();
}
 
int LRE3wxOpenGLPanel::getWidth()
{
    return GetSize().x;
}
 
int LRE3wxOpenGLPanel::getHeight()
{
    return GetSize().y;
}
 
 
void LRE3wxOpenGLPanel::render( wxPaintEvent& evt )
{
    if(!IsShown()) return;
    
    wxGLCanvas::SetCurrent(*m_context);
    wxPaintDC(this); // only to be used in paint events. use wxClientDC to paint outside the paint event

    glViewport(0, 0, getWidth() * GetContentScaleFactor(), getHeight() * GetContentScaleFactor());
    glClearColor(0.1f, 0.1f, 0.1f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_editor->Render(getWidth() * GetContentScaleFactor(), getHeight() * GetContentScaleFactor());

    SwapBuffers();
}