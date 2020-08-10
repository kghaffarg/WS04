#ifndef SDDS_SAIYAN_H__
#define SDDS_SAIYAN_H__
namespace sdds {
	class Saiyan {

		char* m_name;
		int m_dob;
		int m_power;
		bool m_super = false;
		int m_level = 0;
	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);
		~Saiyan();
		void setEmpty();
		void set(const char* name, int dob, int power, int level, bool super = false);
		void set(const char* name, int dob, int power, bool super = false);
		bool isValid() const;
		void display() const;
		bool fight(Saiyan& other);

	};











}
#endif // !SDDS_SAIYAN_H__
