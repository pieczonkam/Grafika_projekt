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

	save_img.AddHandler(new wxJPEGHandler);
	save_img.AddHandler(new wxPNGHandler);
	save_img.AddHandler(new wxBMPHandler);

	///////////////////////////////////////////////////////////////
	m_axes.push_back(Vector(-1.0f, 0.0f, 0.0f));
	m_axes.push_back(Vector(1.0f, 0.0f, 0.0f));
	m_axes.push_back(Vector(0.0f, -1.0f, 0.0f));
	m_axes.push_back(Vector(0.0f, 1.0f, 0.0f));
	m_axes.push_back(Vector(0.0f, 0.0f, -1.0f));
	m_axes.push_back(Vector(0.0f, 0.0f, 1.0f));

	///////////////////////////////////////////////////////////////
	m_arrowheads.push_back(Vector(1.0f, 0.0f, 0.0f));
	m_arrowheads.push_back(Vector(0.95f, -0.025f, 0.0f));
	m_arrowheads.push_back(Vector(1.0f, 0.0f, 0.0f));
	m_arrowheads.push_back(Vector(0.95f, 0.025f, 0.0f));

	m_arrowheads.push_back(Vector(0.0f, 1.0f, 0.0f));
	m_arrowheads.push_back(Vector(-0.025f, 0.95f, 0.0f));
	m_arrowheads.push_back(Vector(0.0f, 1.0f, 0.0f));
	m_arrowheads.push_back(Vector(0.025f, 0.95f, 0.0f));

	m_arrowheads.push_back(Vector(0.0f, 0.0f, 1.0f));
	m_arrowheads.push_back(Vector(-0.025f, 0.0f, 0.95f));
	m_arrowheads.push_back(Vector(0.0f, 0.0f, 1.0f));
	m_arrowheads.push_back(Vector(0.025f, 0.0f, 0.95f));
	
	///////////////////////////////////////////////////////////////

	for (int i = -3; i < 4; ++i)
	{
		if (i)
		{
			m_segments.push_back(Vector(0.25f * (double)i, 0.02f, 0.0f));
			m_segments.push_back(Vector(0.25f * (double)i, -0.02f, 0.0f));
		}
	}

	for (int i = -3; i < 4; ++i)
	{
		if (i)
		{
			m_segments.push_back(Vector(0.02f, 0.25f * (double)i, 0.0f));
			m_segments.push_back(Vector(-0.02f, 0.25f * (double)i, 0.0f));
		}
	}

	for (int i = -3; i < 4; ++i)
	{
		if (i)
		{
			m_segments.push_back(Vector(0.02f, 0.0f, 0.25f * (double)i));
			m_segments.push_back(Vector(-0.02f, 0.0f, 0.25f * (double)i));
		}
	}
}

void GUIMyFrame1::m_panelRepaint(wxUpdateUIEvent& event)
{
	Repaint();
}

void GUIMyFrame1::m_option1OnRadioButton( wxCommandEvent& event )
{
	m_chartChanged = true;
	m_chartChoice = 1;

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
	m_chartChanged = true;
	m_chartChoice = 2;

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
	m_chartChanged = true;
	m_chartChoice = 3;

	m_paramCtrl1->Enable();
	m_paramCtrl2->Enable();
	m_paramCtrl3->Disable();
	m_paramCtrl4->Enable();
	m_paramCtrl5->Enable();
	m_paramCtrl6->Enable();
	m_paramCtrl7->Enable();

	Repaint();
}

void GUIMyFrame1::m_onFunChoice( wxCommandEvent& event )
{
	m_funChanged = true;
	Repaint();
}

void GUIMyFrame1::m_paramCtrl1OnText( wxCommandEvent& event )
{
	wxString phi = m_paramCtrl1->GetValue();
	m_phi = wxAtoi(phi);
	m_phiChanged = true;
	Repaint();
}

void GUIMyFrame1::m_paramCtrl2OnText( wxCommandEvent& event )
{
	wxString theta = m_paramCtrl2->GetValue();
	m_theta = wxAtoi(theta) + 1;
	m_thetaChanged = true;
	Repaint();
}

void GUIMyFrame1::m_paramCtrl3OnText( wxCommandEvent& event )
{
	m_paramCtrl3->GetValue().ToDouble(&m_r);
	m_rChanged = true;
	Repaint();
}

void GUIMyFrame1::m_paramCtrl4OnText( wxCommandEvent& event )
{
	m_paramCtrl4->GetValue().ToDouble(&m_const);
	m_const = true;
	Repaint();
}

void GUIMyFrame1::m_paramCtrl5OnText( wxCommandEvent& event )
{
	m_paramCtrl5->GetValue().ToDouble(&m_epsilon);
	m_epsilonChanged = true;
	Repaint();
}

void GUIMyFrame1::m_paramCtrl6OnText( wxCommandEvent& event )
{
	m_paramCtrl6->GetValue().ToDouble(&m_delta_r);
	m_delta_rChanged = true;
	Repaint();
}

void GUIMyFrame1::m_paramCtrl7OnText(wxCommandEvent& event)
{
	m_paramCtrl7->GetValue().ToDouble(&m_r_max);
	m_r_maxChanged = true;
	Repaint();
}

void GUIMyFrame1::m_pointsJointOnCheckBox( wxCommandEvent& event )
{
	Repaint();
}

void GUIMyFrame1::m_saveButtonOnButtonClick( wxCommandEvent& event )
{
	wxFileDialog file_dlg(this, _("Choose a file"), _(""), _(""), _("JPG files (*.jpg)|*.jpg|PNG files (*.png)|*.png|BMP files (*.bmp)|*.bmp"), wxFD_SAVE);
	if (file_dlg.ShowModal() == wxID_OK)
	{
		save_img = picture_bm.ConvertToImage();
		if (file_dlg.GetPath() != _(""))
			save_img.SaveFile(file_dlg.GetPath());
	}
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

void GUIMyFrame1::m_onAxesReset( wxCommandEvent& event )
{
	m_resetAxes = true;
	Repaint();
}

Matrix GUIMyFrame1::GetRotationMatrix(double rot_x, double rot_y, double rot_z)
{
	Matrix m(1.0f);
	bool rotated = true;
	if (rot_x != m_rotX)
	{
		m = Rotate(m_axes[0], rot_x - m_rotX);
	}
	else if (rot_y != m_rotY)
	{
		m = Rotate(m_axes[2], rot_y - m_rotY);
	}
	else if (rot_z != m_rotZ)
	{
		m = Rotate(m_axes[4], rot_z - m_rotZ);
	}
	else
	{
		rotated = false;
	}

	if (rotated)
		m_rotationHistory = m * m_rotationHistory;

	return m;
}

void GUIMyFrame1::Repaint()
{
	wxClientDC dc1(m_panel);
	picture_bm = wxBitmap(m_panel->GetSize().x, m_panel->GetSize().y);
	wxBufferedDC dc(&dc1, picture_bm);

	dc.SetBackground(wxBrush(wxColour(255, 255, 255)));
	dc.Clear();

	switch (m_chartChoice)
	{
		case 1:
			m_descriptionText->SetLabel(wxT("Spos\u00F3b 1;   f(r, \u03C6, \u03B8) = ") + m_funChoice->GetString(m_funChoice->GetSelection()));
			break;

		case 2:
			m_descriptionText->SetLabel(wxT("Spos\u00F3b 2;   f(r, \u03C6, \u03B8) = ") + m_funChoice->GetString(m_funChoice->GetSelection()));
			break;

		case 3:
			m_descriptionText->SetLabel(wxT("Spos\u00F3b 3;   f(r, \u03C6, \u03B8) = ") + m_funChoice->GetString(m_funChoice->GetSelection()));
			break;

		default:
			break;
	}

	//Resetowanie ustawien osi wspolrzednych
	if (m_resetAxes) Reset();

	double rot_x = m_rotateSlider1->GetValue();
	double rot_y = m_rotateSlider2->GetValue();
	double rot_z = m_rotateSlider3->GetValue();

	int w, h;
	m_panel->GetSize(&w, &h);
	double width = (double)w;
	double height = (double)h;
	double depth = 2.0f;

	Matrix rotation = GetRotationMatrix(rot_x, rot_y, rot_z);
	Matrix perspective = Perspective(width, height, depth);

	//Rysowanie osi wspolrzednych
	DrawAxes(dc, rotation, perspective);

	/// updating points
	if (m_phiChanged || m_thetaChanged || m_rChanged || m_funChanged || m_chartChanged)
	{
		getPoints();
		m_phiChanged = m_thetaChanged = m_rChanged = m_funChanged = m_chartChanged = false;
	}

	/// iterating over points to draw
	for (auto& v : points) {

		/// calculating on screen position of the point
		Vector pt{ rotation * v.first };
		
		v.first = pt;

		pt = perspective * pt;

		pt.Normalize();
	
		/// setting colour and drawing
		dc.SetPen(wxPen{ v.second });

		/// it's slow as hell so have to look into ways of drawing all points in a single function to speed this up
		dc.DrawPoint(pt(0), pt(1));
	}

	m_rotX = rot_x;
	m_rotY = rot_y;
	m_rotZ = rot_z;
}

void GUIMyFrame1::DrawAxes(wxBufferedDC& dc, Matrix rotation, Matrix perspective)
{
	dc.SetPen(wxPen(wxColour(0, 0, 0)));
	for (int vec = 0; vec < m_axes.size(); vec += 2)
	{
		Vector begin = m_axes[vec];
		Vector end = m_axes[vec + 1];

		begin = rotation * begin;
		end = rotation * end;

		m_axes[vec] = begin;
		m_axes[vec + 1] = end;

		begin = perspective * begin;
		end = perspective * end;

		//Normalizowanie wektorow
		begin.Normalize();
		end.Normalize();

		//Rysowanie
		dc.DrawLine(begin(0), begin(1), end(0), end(1));
	}

	for (int i = 0; i < m_arrowheads.size(); i += 2)
	{
		Vector begin = m_arrowheads[i];
		Vector end = m_arrowheads[i + 1];

		begin = rotation * begin;
		end = rotation * end;

		m_arrowheads[i] = begin;
		m_arrowheads[i + 1] = end;

		begin = perspective * begin;
		end = perspective * end;

		//Normalizowanie wektorow
		begin.Normalize();
		end.Normalize();

		dc.DrawLine(begin(0), begin(1), end(0), end(1));
	}

	for (int i = 0; i < m_segments.size(); i += 2)
	{
		Vector begin = m_segments[i];
		Vector end = m_segments[i + 1];

		begin = rotation * begin;
		end = rotation * end;

		m_segments[i] = begin;
		m_segments[i + 1] = end;

		begin = perspective * begin;
		end = perspective * end;

		//Normalizowanie wektorow
		begin.Normalize();
		end.Normalize();

		dc.DrawLine(begin(0), begin(1), end(0), end(1));
	}
}

void GUIMyFrame1::Reset()
{
	///////////////////////////////////////////////////////////////
	m_axes[0] = Vector(-1.0f, 0.0f, 0.0f);
	m_axes[1] = Vector(1.0f, 0.0f, 0.0f);
	m_axes[2] = Vector(0.0f, -1.0f, 0.0f);
	m_axes[3] = Vector(0.0f, 1.0f, 0.0f);
	m_axes[4] = Vector(0.0f, 0.0f, -1.0f);
	m_axes[5] = Vector(0.0f, 0.0f, 1.0f);

	///////////////////////////////////////////////////////////////
	m_arrowheads[0] = Vector(1.0f, 0.0f, 0.0f);
	m_arrowheads[1] = Vector(0.95f, -0.025f, 0.0f);
	m_arrowheads[2] = Vector(1.0f, 0.0f, 0.0f);
	m_arrowheads[3] = Vector(0.95f, 0.025f, 0.0f);

	m_arrowheads[4] = Vector(0.0f, 1.0f, 0.0f);
	m_arrowheads[5] = Vector(-0.025f, 0.95f, 0.0f);
	m_arrowheads[6] = Vector(0.0f, 1.0f, 0.0f);
	m_arrowheads[7] = Vector(0.025f, 0.95f, 0.0f);

	m_arrowheads[8] = Vector(0.0f, 0.0f, 1.0f);
	m_arrowheads[9] = Vector(-0.025f, 0.0f, 0.95f);
	m_arrowheads[10] = Vector(0.0f, 0.0f, 1.0f);
	m_arrowheads[11] = Vector(0.025f, 0.0f, 0.95f);

	///////////////////////////////////////////////////////////////
	int j = 0;
	for (int i = -3; i < 4; ++i)
	{
		if (i)
		{
			m_segments[j++] = Vector(0.25f * (double)i, 0.02f, 0.0f);
			m_segments[j++] = Vector(0.25f * (double)i, -0.02f, 0.0f);
		}
	}
	for (int i = -3; i < 4; ++i)
	{
		if (i)
		{
			m_segments[j++] = Vector(0.02f, 0.25f * (double)i, 0.0f);
			m_segments[j++] = Vector(-0.02f, 0.25f * (double)i, 0.0f);
		}
	}
	for (int i = -3; i < 4; ++i)
	{
		if (i)
		{
			m_segments[j++] = Vector(0.02f, 0.0f, 0.25f * (double)i);
			m_segments[j++] = Vector(-0.02f, 0.0f, 0.25f * (double)i);
		}
	}

	///////////////////////////////////////////////////////////////
	m_rotateSlider1->SetValue(0);
	m_rotateSlider2->SetValue(0);
	m_rotateSlider3->SetValue(0);

	m_rotateVal1->SetLabel(wxString::Format(wxT("%d"), m_rotateSlider1->GetValue()));
	m_rotateVal2->SetLabel(wxString::Format(wxT("%d"), m_rotateSlider2->GetValue()));
	m_rotateVal3->SetLabel(wxString::Format(wxT("%d"), m_rotateSlider3->GetValue()));

	m_rotX = 0.0;
	m_rotY = 0.0;
	m_rotZ = 0.0;

	m_rotationHistory = Matrix(1.0f);
	
	getPoints();

	m_resetAxes = false;
}

void GUIMyFrame1::getPoints() 
{
	if (m_option1->GetValue() || m_option2->GetValue() || m_option3->GetValue())
	{
		points.clear();
		if (m_theta < 1 || m_phi < 1 || m_r < 0)
			return;

		/// preallocating memory
		points.reserve(m_phi * m_theta);

		/// iteration steps
		double dTheta{ M_PI / m_theta };
		double dPhi{ 2 * M_PI / m_phi };

		double min{ 1e8 }, max{ 0 };

		/// finding min/max of a function
		/// could maybe try do do something with analysis to avoid iterating twice like this
		for (int i{ 0 }; i < m_theta; ++i) {
			double aTheta{ i * dTheta };
			for (int j{ 0 }; j < m_phi; ++j) {
				double aPhi{ j * dPhi };

				double fVal{ 0.0 };
				switch (funNr()) {
				case 1:
					fVal = F1(aTheta, aPhi, m_r);
					break;
				case 2:
					fVal = F2(aTheta, aPhi, m_r);
					break;
				case 3:
					fVal = F3(aTheta, aPhi, m_r);
					break;
				default:
					break;
				}

				if (fVal < min)
					min = fVal;
				else if (fVal > max)
					max = fVal;
			}
		}

		m_descriptionText->SetLabel(wxString::Format(wxT("%f"), max));

		/// creating points and assigning them place in space
		for (int i{ 0 }; i < m_theta; ++i) {
			double aTheta{ i * dTheta };

			for (int j{ 0 }; j < m_phi; ++j) {
				double aPhi{ j * dPhi };

				double fVal{ 0.0 };

				switch (funNr()) {
				case 1:
					fVal = F1(aTheta, aPhi, m_r);
					break;
				case 2:
					fVal = F2(aTheta, aPhi, m_r);
					break;
				case 3:
					fVal = F3(aTheta, aPhi, m_r);
					break;
				default:
					break;
				}

				/// preparing and pushing point to vector
				std::pair<Vector, wxColour> pt;
				double colour{ utility::map(fVal, min, max, 0, 1) };
				double r1{ utility::map(m_r, 0, 20, 0, 1) };
				double r2 = colour;
				
				/// spherical to cartesian coordinates
				if (m_option1->GetValue())
				{
					pt.first(0) = r1 * sin(aTheta) * cos(aPhi);
					pt.first(1) = r1 * sin(aTheta) * sin(aPhi);
					pt.first(2) = r1 * cos(aTheta);
					pt.second = utility::mapToColour(colour);
				}
				if (m_option2->GetValue())
				{
					pt.first(0) = 0.8f * r2 * sin(aTheta) * cos(aPhi);
					pt.first(1) = 0.8f * r2 * sin(aTheta) * sin(aPhi);
					pt.first(2) = 0.8f * r2 * cos(aTheta);
					pt.second = utility::mapToColour(colour);
				}

				pt.first = m_rotationHistory * pt.first;
				points.push_back(pt);
			}
		}
	}
	return;
}

int GUIMyFrame1::funNr() const {
	if (m_funChoice->GetSelection() == 0)
		return 1;
	if (m_funChoice->GetSelection() == 1)
		return 2;
	if (m_funChoice->GetSelection() == 2)
		return 3;

	return 0;
}

double GUIMyFrame1::F1(double _theta, double _phi, double _r) const {
	return cos(_theta) + sin(_phi) * _r;
}
double GUIMyFrame1::F2(double _theta, double _phi, double _r) const {
	return ( exp(_r) * sin(_phi) * cos(_theta) ) / (_r * _r + 1.0f);
}
double GUIMyFrame1::F3(double _theta, double _phi, double _r) const {
	return _r * _r * _r * cos(_theta) * sin(_phi) * cos(_phi);
}

