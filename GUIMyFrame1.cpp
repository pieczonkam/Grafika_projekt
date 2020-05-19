#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	m_paramCtrl1->Disable();
	m_paramCtrl2->Disable();
	m_paramCtrl3->Disable();
	m_paramCtrl4->Disable();
	m_paramCtrl5->Disable();
	m_paramCtrl6->Disable();
	m_paramCtrl7->Disable();
}

void GUIMyFrame1::m_option1OnRadioButton( wxCommandEvent& event )
{
	m_paramCtrl1->Enable();
	m_paramCtrl2->Enable();
	m_paramCtrl3->Enable();
	m_paramCtrl4->Disable();
	m_paramCtrl5->Disable();
	m_paramCtrl6->Disable();
	m_paramCtrl7->Disable();
}

void GUIMyFrame1::m_option2OnRadioButton( wxCommandEvent& event )
{
	m_paramCtrl1->Enable();
	m_paramCtrl2->Enable();
	m_paramCtrl3->Enable();
	m_paramCtrl4->Disable();
	m_paramCtrl5->Disable();
	m_paramCtrl6->Disable();
	m_paramCtrl7->Disable();
}

void GUIMyFrame1::m_option3OnRadioButton( wxCommandEvent& event )
{
	m_paramCtrl1->Enable();
	m_paramCtrl2->Enable();
	m_paramCtrl3->Disable();
	m_paramCtrl4->Enable();
	m_paramCtrl5->Enable();
	m_paramCtrl6->Enable();
	m_paramCtrl7->Enable();
}

void GUIMyFrame1::m_paramCtrl1OnText( wxCommandEvent& event )
{
// TODO: Implement m_paramCtrl1OnText
}

void GUIMyFrame1::m_paramCtrl2OnText( wxCommandEvent& event )
{
// TODO: Implement m_paramCtrl2OnText
}

void GUIMyFrame1::m_paramCtrl3OnText( wxCommandEvent& event )
{
// TODO: Implement m_paramCtrl3OnText
}

void GUIMyFrame1::m_paramCtrl4OnText( wxCommandEvent& event )
{
// TODO: Implement m_paramCtrl4OnText
}

void GUIMyFrame1::m_paramCtrl5OnText( wxCommandEvent& event )
{
// TODO: Implement m_paramCtrl5OnText
}

void GUIMyFrame1::m_paramCtrl6OnText( wxCommandEvent& event )
{
// TODO: Implement m_paramCtrl6OnText
}

void GUIMyFrame1::m_pointsJointOnCheckBox( wxCommandEvent& event )
{
// TODO: Implement m_pointsJointOnCheckBox
}

void GUIMyFrame1::m_saveButtonOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_saveButtonOnButtonClick
}

void GUIMyFrame1::m_rotateSlider1OnScroll( wxScrollEvent& event )
{
// TODO: Implement m_rotateSlider1OnScroll
}

void GUIMyFrame1::m_rotateSlider2OnScroll( wxScrollEvent& event )
{
// TODO: Implement m_rotateSlider2OnScroll
}

void GUIMyFrame1::m_rotateSlider3OnScroll( wxScrollEvent& event )
{
// TODO: Implement m_rotateSlider3OnScroll
}


