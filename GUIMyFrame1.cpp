#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	m_rotateSlider1->SetRange(0, 360); m_rotateSlider1->SetValue(0);
	m_rotateSlider2->SetRange(0, 360); m_rotateSlider2->SetValue(0);
	m_rotateSlider3->SetRange(0, 360); m_rotateSlider3->SetValue(0);

	m_descriptionText->SetLabel("Prosz\u0119 wybra\u0107 rodzaj wykresu");

	m_paramCtrl1->Disable();
	m_paramCtrl2->Disable();
	m_paramCtrl3->Disable();
	m_paramCtrl4->Disable();
	m_paramCtrl5->Disable();
	m_paramCtrl6->Disable();
	m_paramCtrl7->Disable();

	m_axes.push_back(Vector(-1.0f, 0.0f, 0.0f));
	m_axes.push_back(Vector(1.0f, 0.0f, 0.0f));
	m_axes.push_back(Vector(0.0f, -1.0f, 0.0f));
	m_axes.push_back(Vector(0.0f, 1.0f, 0.0f));
	m_axes.push_back(Vector(0.0f, 0.0f, -1.0f));
	m_axes.push_back(Vector(0.0, 0.0, 1.0f));
}

void GUIMyFrame1::m_panelRepaint(wxUpdateUIEvent& event)
{
	Repaint();
}

void GUIMyFrame1::m_option1OnRadioButton( wxCommandEvent& event )
{
	m_descriptionText->SetLabel("Wykres 1");

	m_paramCtrl1->Enable();
	m_paramCtrl2->Enable();
	m_paramCtrl3->Enable();
	m_paramCtrl4->Disable();
	m_paramCtrl5->Disable();
	m_paramCtrl6->Disable();
	m_paramCtrl7->Disable();

	Repaint();
}

void GUIMyFrame1::m_option2OnRadioButton( wxCommandEvent& event )
{
	m_descriptionText->SetLabel("Wykres 2");

	m_paramCtrl1->Enable();
	m_paramCtrl2->Enable();
	m_paramCtrl3->Enable();
	m_paramCtrl4->Disable();
	m_paramCtrl5->Disable();
	m_paramCtrl6->Disable();
	m_paramCtrl7->Disable();

	Repaint();
}

void GUIMyFrame1::m_option3OnRadioButton( wxCommandEvent& event )
{
	m_descriptionText->SetLabel("Wykres 3");

	m_paramCtrl1->Enable();
	m_paramCtrl2->Enable();
	m_paramCtrl3->Disable();
	m_paramCtrl4->Enable();
	m_paramCtrl5->Enable();
	m_paramCtrl6->Enable();
	m_paramCtrl7->Enable();

	Repaint();
}

void GUIMyFrame1::m_paramCtrl1OnText( wxCommandEvent& event )
{
	m_paramCtrl1->GetValue().ToDouble(&phi);
	Repaint();
}

void GUIMyFrame1::m_paramCtrl2OnText( wxCommandEvent& event )
{
	m_paramCtrl2->GetValue().ToDouble(&teta);
	Repaint();
}

void GUIMyFrame1::m_paramCtrl3OnText( wxCommandEvent& event )
{
	m_paramCtrl3->GetValue().ToDouble(&r);
	Repaint();
}

void GUIMyFrame1::m_paramCtrl4OnText( wxCommandEvent& event )
{
	Repaint();
}

void GUIMyFrame1::m_paramCtrl5OnText( wxCommandEvent& event )
{
	Repaint();
}

void GUIMyFrame1::m_paramCtrl6OnText( wxCommandEvent& event )
{
	Repaint();
}

void GUIMyFrame1::m_pointsJointOnCheckBox( wxCommandEvent& event )
{
	Repaint();
}

void GUIMyFrame1::m_saveButtonOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_saveButtonOnButtonClick
}

void GUIMyFrame1::m_rotateSlider1OnScroll( wxScrollEvent& event )
{
	m_rotateVal1->SetLabel(wxString::Format(wxT("%d"), m_rotateSlider1->GetValue()));
	Repaint();
}

void GUIMyFrame1::m_rotateSlider2OnScroll( wxScrollEvent& event )
{
	m_rotateVal2->SetLabel(wxString::Format(wxT("%d"), m_rotateSlider2->GetValue()));
	Repaint();
}

void GUIMyFrame1::m_rotateSlider3OnScroll( wxScrollEvent& event )
{
	m_rotateVal3->SetLabel(wxString::Format(wxT("%d"), m_rotateSlider3->GetValue()));
	Repaint();
}

void GUIMyFrame1::Repaint()
{
	wxClientDC dc1(m_panel);
	wxBufferedDC dc(&dc1);

	dc.SetBackground(wxBrush(wxColour(255, 255, 255)));
	dc.Clear();

	//Transformacje (w tym przypadku tylko rotacja)
	double rot_x = m_rotateSlider1->GetValue();
	double rot_y = m_rotateSlider2->GetValue();
	double rot_z = m_rotateSlider3->GetValue();

	for (int vec = 0; vec < 6; vec += 2)
	{
		Vector begin = m_axes[vec];
		Vector end = m_axes[vec + 1];

		if (rot_x != m_rotX)
		{
			begin = Rotate(m_axes[0], rot_x - m_rotX) * begin;
			end = Rotate(m_axes[0], rot_x - m_rotX) * end;
		}
		else if (rot_y != m_rotY)
		{
			begin = Rotate(m_axes[2], rot_y - m_rotY) * begin;
			end = Rotate(m_axes[2], rot_y - m_rotY) * end;
		}
		else if (rot_z != m_rotZ)
		{ 
			begin = Rotate(m_axes[4], rot_z - m_rotZ) * begin;
			end = Rotate(m_axes[4], rot_z - m_rotZ) * end;
		}

		m_axes[vec] = begin;
		m_axes[vec + 1] = end;

		int w, h;
		m_panel->GetSize(&w, &h);
		double width = (double)w;
		double height = (double)h;
		double depth = -2.0f;

		begin = Perspective(width, height, depth) * begin;
		end = Perspective(width, height, depth) * end;

		//Normowanie wektorow
		for (int i = 0; i < 3; ++i)
		{
			begin.Set(i, begin.Get(i) / begin.Get(3));
			end.Set(i, end.Get(i) / end.Get(3));
		}

		switch (vec)
		{
			case 0:
				dc.SetPen(wxPen(wxColour(255, 0, 0))); //OX
				break;
			case 2:
				dc.SetPen(wxPen(wxColour(0, 255, 0))); //OY
				break;
			case 4:
				dc.SetPen(wxPen(wxColour(0, 0, 255))); //OZ
				break;
		}

		//Rysowanie
		dc.DrawLine(begin.Get(0), begin.Get(1), end.Get(0), end.Get(1));
	}

	m_rotX = rot_x;
	m_rotY = rot_y;
	m_rotZ = rot_z;
}


