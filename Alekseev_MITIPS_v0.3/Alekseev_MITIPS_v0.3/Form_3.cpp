#include "Form_3.h"
#include "Classes.h"
#include "Functions.h"
#include "mysql.h"


extern std::vector<Feature> Features;
extern std::vector<Ñlinical> Ñlinicals;
extern std::set<std::string> feature_names;
extern std::set<std::string> disease_names;

System::Void AlekseevMITIPSv03::Form_3::listBox8_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	String^ selected = listBox8->SelectedItem->ToString();
	MessageBox::Show(selected);
	listBox2->Items->Clear();
	listBox2->Items->Add(selected);
	return System::Void();
}

System::Void AlekseevMITIPSv03::Form_3::listBox9_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	String^ selected = listBox9->SelectedItem->ToString();
	MessageBox::Show(selected);
	bool q = false;
	if (!listBox1->Items->Contains(listBox9->SelectedItem)) {
		listBox1->Items->Add(selected);
	}
	return System::Void();
}

System::Void AlekseevMITIPSv03::Form_3::listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	listBox1->Items->Clear();
	return System::Void();
}

System::Void AlekseevMITIPSv03::Form_3::listBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void AlekseevMITIPSv03::Form_3::button1_Click(System::Object^ sender, System::EventArgs^ e)
{

	return System::Void();
}
