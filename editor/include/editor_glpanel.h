#pragma once
#include <gl/glew.h>

#include "wx/wx.h"
#include "wx/time.h"
#include "wx/glcanvas.h"

#include "editor.h"
#include "editor_input.h"

class LRE3wxOpenGLPanel : public wxGLCanvas
{
public:
    LRE3Editor* m_editor;
    LRE3EditorInput m_input;

private:
    wxGLContext* m_context;
    wxGLContextAttrs m_contextAttribs;
    wxTimer m_timer;
    wxLongLong m_prevTime;
    wxLongLong m_currTime;
    float m_deltaTime;
    wxPoint m_lastMouse;

    GLuint m_outFramebuffer;

public:
    LRE3wxOpenGLPanel(wxFrame* parent, int* args);
    virtual ~LRE3wxOpenGLPanel();

    void resized(wxSizeEvent& evt);

    int getWidth();
    int getHeight();

    void update(wxTimerEvent& evt);
    void render(wxPaintEvent& evt);

    void mouseMoved(wxMouseEvent& event);
	void mouseDown(wxMouseEvent& event);
	void mouseWheelMoved(wxMouseEvent& event);
	void mouseReleased(wxMouseEvent& event);
	void rightClick(wxMouseEvent& event);
	void mouseLeftWindow(wxMouseEvent& event);
	void keyPressed(wxKeyEvent& event);
	void keyReleased(wxKeyEvent& event);

    DECLARE_EVENT_TABLE()
};