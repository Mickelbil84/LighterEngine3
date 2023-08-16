#define GL_SILENCE_DEPRECATION

#include "editor.h"
#include "editor_ui.h"
#include "editor_glpanel.h"

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class LRE3EditorApp : public wxApp
{
public:
    virtual bool OnInit();

    LRE3Editor m_editor;
};
wxIMPLEMENT_APP(LRE3EditorApp);

bool LRE3EditorApp::OnInit()
{
    LRE3EditorUI* window = new LRE3EditorUI(nullptr);

    ////////////////
    // Add GLPanel
    ////////////////
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    int args[] = {WX_GL_RGBA, WX_GL_DOUBLEBUFFER, WX_GL_DEPTH_SIZE, 16, 0};

    LRE3wxOpenGLPanel* glPanel = new LRE3wxOpenGLPanel((wxFrame*)window->m_OpenGLContainer, args);
    sizer->Add(glPanel, 1, wxEXPAND);

    glPanel->m_editor = &m_editor;
    window->m_OpenGLContainer->SetSizer(sizer);
    window->m_OpenGLContainer->SetAutoLayout(true);
    ////////////////

    m_editor.Init();

    window->Show(true);
    return true;
}