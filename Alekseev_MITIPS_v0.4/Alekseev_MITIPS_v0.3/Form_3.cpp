#include "Form_3.h"
#include "Classes.h"
#include "Functions.h"
#include "mysql.h"


extern std::vector<Feature> Features;
extern std::vector<Ñlinical> Ñlinicals;
extern std::set<std::string> feature_names;
extern std::set<std::string> disease_names;

Ñlinical C("",{});
std::set<Feature> Features_set;


System::Void AlekseevMITIPSv03::Form_3::Form_3_Load(System::Object^ sender, System::EventArgs^ e)
{
	listBox9->Items->Clear();
	
	for (auto i : Features) {
		String^ S;
		S = Convert_string_to_String(i.feature_name, S);
		listBox9->Items->Add(S);
	}



	return System::Void();
}

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
		std::string s;
		Convert_String_to_string(listBox9->SelectedItem->ToString(), s);
		Feature F(s);
		Features_set.insert(F);
	}
	return System::Void();
}

System::Void AlekseevMITIPSv03::Form_3::listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	listBox8->Items->Clear();
	for (Feature i : Features) {
		std::string f;
		f = Convert_String_to_string(listBox1->SelectedItem->ToString(), f);
		if (f == i.feature_name) {
			for (std::string ff : i.possible_values) {
				String^ S;
				S = Convert_string_to_String(ff, S);
				listBox8->Items->Add(S);
			}
		}
	}
	return System::Void();
}

System::Void AlekseevMITIPSv03::Form_3::listBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void AlekseevMITIPSv03::Form_3::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	for (Ñlinical C : Ñlinicals) {
		if (C.disease_features == Features_set) {
			String^ S;
			S = Convert_string_to_String(C.disease_name, S);
			MessageBox::Show("Ïğåäïîëîãàåìûé äèàãíîç " + S);
		}
		else {
			String^ S;
			S = Convert_string_to_String(C.disease_name, S);
			MessageBox::Show("Äèàãíîç " + S + " íå ïîäõîäèò");
		}
	}




	return System::Void();
}
