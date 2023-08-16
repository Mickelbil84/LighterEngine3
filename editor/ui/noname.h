///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/panel.h>
#include <wx/treectrl.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class LRE3EditorUIBase
///////////////////////////////////////////////////////////////////////////////
class LRE3EditorUIBase : public wxFrame
{
	private:

	protected:
		wxAuiToolBar* m_auiToolBar1;
		wxAuiToolBarItem* m_tool14;
		wxAuiToolBarItem* m_tool15;
		wxAuiToolBarItem* m_tool16;
		wxAuiToolBarItem* m_tool17;
		wxAuiToolBarItem* m_tool18;
		wxAuiToolBarItem* m_tool19;
		wxAuiToolBarItem* m_tool20;
		wxAuiToolBarItem* m_tool21;
		wxAuiToolBarItem* m_tool22;
		wxAuiToolBarItem* m_tool23;
		wxAuiToolBar* m_auiToolBar5;
		wxAuiToolBarItem* m_tool24;
		wxAuiToolBarItem* m_tool25;
		wxAuiToolBarItem* m_tool26;
		wxNotebook* m_notebook1;
		wxPanel* m_panel2;
		wxTreeCtrl* m_treeCtrl2;
		wxPanel* m_panel3;
		wxPropertyGrid* m_propertyGrid1;
		wxStatusBar* m_statusBar1;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxMenu* m_menu2;

	public:
		wxPanel* m_OpenGLContainer;

		LRE3EditorUIBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("LighterEngine3 Editor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1360,768 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~LRE3EditorUIBase();

};

