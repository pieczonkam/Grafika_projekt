///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 840,530 ), wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );

	bSizer4->Add( m_panel, 1, wxEXPAND | wxALL, 5 );


	bSizer2->Add( bSizer4, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_descriptionText = new wxStaticText( this, wxID_ANY, wxT("Opis wykresu"), wxDefaultPosition, wxDefaultSize, 0 );
	m_descriptionText->Wrap( -1 );
	bSizer5->Add( m_descriptionText, 0, wxALL, 5 );


	bSizer2->Add( bSizer5, 0, wxALL|wxEXPAND, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_option1 = new wxRadioButton( this, wxID_ANY, wxT("Wykres 1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_option1, 0, wxALL, 5 );

	m_option2 = new wxRadioButton( this, wxID_ANY, wxT("Wykres 2"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_option2, 0, wxALL, 5 );

	m_option3 = new wxRadioButton( this, wxID_ANY, wxT("Wykres 3"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_option3, 0, wxALL, 5 );


	bSizer6->Add( bSizer8, 0, wxALL|wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_paramText1 = new wxStaticText( this, wxID_ANY, wxT("il. pkt. \u03C6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_paramText1->Wrap( -1 );
	fgSizer1->Add( m_paramText1, 0, wxALIGN_RIGHT|wxALL, 5 );

	m_paramCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_paramCtrl1, 0, wxALL, 5 );

	m_paramText2 = new wxStaticText( this, wxID_ANY, wxT("il. pkt. \u03B8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_paramText2->Wrap( -1 );
	fgSizer1->Add( m_paramText2, 0, wxALIGN_RIGHT|wxALL, 5 );

	m_paramCtrl2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_paramCtrl2, 0, wxALL, 5 );

	m_paramText3 = new wxStaticText( this, wxID_ANY, wxT("r"), wxDefaultPosition, wxDefaultSize, 0 );
	m_paramText3->Wrap( -1 );
	fgSizer1->Add( m_paramText3, 0, wxALIGN_RIGHT|wxALL, 5 );

	m_paramCtrl3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_paramCtrl3, 0, wxALL, 5 );

	m_paramText4 = new wxStaticText( this, wxID_ANY, wxT("const"), wxDefaultPosition, wxDefaultSize, 0 );
	m_paramText4->Wrap( -1 );
	fgSizer1->Add( m_paramText4, 0, wxALIGN_RIGHT|wxALL, 5 );

	m_paramCtrl4 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_paramCtrl4, 0, wxALL, 5 );

	m_paramText5 = new wxStaticText( this, wxID_ANY, wxT("\u03B5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_paramText5->Wrap( -1 );
	fgSizer1->Add( m_paramText5, 0, wxALIGN_RIGHT|wxALL, 5 );

	m_paramCtrl5 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_paramCtrl5, 0, wxALL, 5 );

	m_paramText6 = new wxStaticText( this, wxID_ANY, wxT("\u0394r"), wxDefaultPosition, wxDefaultSize, 0 );
	m_paramText6->Wrap( -1 );
	fgSizer1->Add( m_paramText6, 0, wxALIGN_RIGHT|wxALL, 5 );

	m_paramCtrl6 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_paramCtrl6, 0, wxALL, 5 );

	m_paramText7 = new wxStaticText( this, wxID_ANY, wxT(" r_max"), wxDefaultPosition, wxDefaultSize, 0 );
	m_paramText7->Wrap( -1 );
	fgSizer1->Add( m_paramText7, 0, wxALIGN_RIGHT|wxALL, 5 );

	m_paramCtrl7 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_paramCtrl7, 0, wxALL, 5 );


	bSizer6->Add( fgSizer1, 1, wxALIGN_CENTER|wxALL, 5 );

	m_pointsJoint = new wxCheckBox( this, wxID_ANY, wxT("Po\u0142\u0105cz punkty"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_pointsJoint, 0, wxALIGN_CENTER|wxALIGN_TOP|wxALL, 5 );

	m_saveButton = new wxButton( this, wxID_ANY, wxT("Zapisz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_saveButton, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer3->Add( bSizer6, 0, wxALIGN_CENTER, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_rotateText1 = new wxStaticText( this, wxID_ANY, wxT("Obr\u00F3t X"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rotateText1->Wrap( -1 );
	fgSizer2->Add( m_rotateText1, 0, wxALL, 5 );

	m_rotateSlider1 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	fgSizer2->Add( m_rotateSlider1, 0, wxALL, 5 );

	m_rotateVal1 = new wxStaticText( this, wxID_ANY, wxT("Warto\u015B\u0107"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rotateVal1->Wrap( -1 );
	fgSizer2->Add( m_rotateVal1, 0, wxALL, 5 );

	m_rotateText2 = new wxStaticText( this, wxID_ANY, wxT("Obr\u00F3t Y"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rotateText2->Wrap( -1 );
	fgSizer2->Add( m_rotateText2, 0, wxALL, 5 );

	m_rotateSlider2 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	fgSizer2->Add( m_rotateSlider2, 0, wxALL, 5 );

	m_rotateVal2 = new wxStaticText( this, wxID_ANY, wxT("Warto\u015B\u0107"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rotateVal2->Wrap( -1 );
	fgSizer2->Add( m_rotateVal2, 0, wxALL, 5 );

	m_rotateText3 = new wxStaticText( this, wxID_ANY, wxT("Obr\u00F3t Z"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rotateText3->Wrap( -1 );
	fgSizer2->Add( m_rotateText3, 0, wxALL, 5 );

	m_rotateSlider3 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	fgSizer2->Add( m_rotateSlider3, 0, wxALL, 5 );

	m_rotateVal3 = new wxStaticText( this, wxID_ANY, wxT("Warto\u015B\u0107"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rotateVal3->Wrap( -1 );
	fgSizer2->Add( m_rotateVal3, 0, wxALL, 5 );


	bSizer7->Add( fgSizer2, 0, wxALIGN_BOTTOM|wxALL, 5 );


	bSizer3->Add( bSizer7, 1, wxEXPAND, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_option1->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::m_option1OnRadioButton ), NULL, this );
	m_option2->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::m_option2OnRadioButton ), NULL, this );
	m_option3->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::m_option3OnRadioButton ), NULL, this );
	m_paramCtrl1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl1OnText ), NULL, this );
	m_paramCtrl2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl2OnText ), NULL, this );
	m_paramCtrl3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl3OnText ), NULL, this );
	m_paramCtrl4->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl4OnText ), NULL, this );
	m_paramCtrl5->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl5OnText ), NULL, this );
	m_paramCtrl6->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl6OnText ), NULL, this );
	m_paramCtrl7->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl1OnText ), NULL, this );
	m_pointsJoint->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::m_pointsJointOnCheckBox ), NULL, this );
	m_saveButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_saveButtonOnButtonClick ), NULL, this );
	m_rotateSlider1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider2->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider3->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_option1->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::m_option1OnRadioButton ), NULL, this );
	m_option2->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::m_option2OnRadioButton ), NULL, this );
	m_option3->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::m_option3OnRadioButton ), NULL, this );
	m_paramCtrl1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl1OnText ), NULL, this );
	m_paramCtrl2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl2OnText ), NULL, this );
	m_paramCtrl3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl3OnText ), NULL, this );
	m_paramCtrl4->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl4OnText ), NULL, this );
	m_paramCtrl5->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl5OnText ), NULL, this );
	m_paramCtrl6->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl6OnText ), NULL, this );
	m_paramCtrl7->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::m_paramCtrl1OnText ), NULL, this );
	m_pointsJoint->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::m_pointsJointOnCheckBox ), NULL, this );
	m_saveButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_saveButtonOnButtonClick ), NULL, this );
	m_rotateSlider1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_rotateSlider1OnScroll ), NULL, this );
	m_rotateSlider2->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider2->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_rotateSlider2OnScroll ), NULL, this );
	m_rotateSlider3->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );
	m_rotateSlider3->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_rotateSlider3OnScroll ), NULL, this );

}
