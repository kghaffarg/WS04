#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Saiyan.h"
using namespace std;
namespace sdds {

	Saiyan::Saiyan() {
		setEmpty();			
	}
	Saiyan::Saiyan(const char* name, int dob, int power) {
		if (name == nullptr || dob <= 0 || dob > 2020 || power < 0)
			 {
			setEmpty();
		}
		else {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
		}
	}
	Saiyan::~Saiyan() {
		delete[] m_name;
		m_name = nullptr;
	}
	void Saiyan::setEmpty() {
		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_level = 0;
	}
	

	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {

		if (super == false) {
			setEmpty();
		}
		else if (name[0] == '\0' || dob <= 0 || power < 0) {
			setEmpty();
		}
		else{
			
			if (m_name != nullptr) {
				delete[] m_name;
			}

			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_level = level;
			m_super = super;

		}

	}
	void Saiyan::set(const char* name, int dob, int power, bool super) {
		if (name == nullptr || name[0] == '\0' || dob < 0 || dob > 2020 || power <= 0 ) {
			setEmpty();
		}
		else {
			if (m_name != nullptr) {
				delete[] m_name;
			}
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
		}
	}
	bool Saiyan::isValid() const {
		return (m_name != nullptr && m_name[0] != '\0' && m_dob > 0 && m_dob < 2020 && m_power > 0);
	}
	


	void Saiyan::display() const {
			if (m_name == nullptr || m_name[0] == '\0' || m_dob <= 0 || m_dob > 2020 || m_power < 0 || m_level < 0) {
			cout << "Invalid Saiyan!" << endl;
			}
			else {
				cout << m_name << endl;
				cout.width(10);
				cout.setf(ios::fixed);
				cout << "DOB: " << m_dob << endl;
				cout.width(10);
				cout.setf(ios::fixed);
				cout << "Power: " << m_power << endl;
				if (m_super) {
					cout.width(10);
					cout.setf(ios::fixed);
					cout << "Super: " << "yes" << endl;
					cout.width(10);
					cout.setf(ios::fixed);
					cout << "Level: " << m_level << endl;
				}
				else {
					cout.width(10);
					cout.setf(ios::fixed);
					cout << "Super: " << "no" << endl;
				

				}
			}
	}

	

	bool Saiyan::fight(Saiyan& other) {
		bool win = false;
		
		if (isValid() && other.isValid()) {
			
			if (m_super) {

				int temp = m_power * m_level * 0.1;
				m_power += temp;

			}
			if (other.m_super) {
					int temp2 = other.m_power * other.m_level * 0.1;
					other.m_power += temp2;
				
			}
			if (m_power > other.m_power) win = true;
				
		}

		return win;

	}



}