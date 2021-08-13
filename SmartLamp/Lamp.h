#ifndef LAMP_H
#define LAMP_H

class Lamp
{
private:
	bool m_power;     // ���� ������������
	bool m_mode;      // ����� �����������	
	bool m_signal;    // ������ �����������
	int m_regulation; // ��������� ����������
	int m_temperature;// ����������� �������

	void temperatureCalculation(int celsius);// ���������� �����������
	void overheating();                      // �������� ��������

public:
	//Lamp();                       // ���������� �������� ��������
	void setOff();					// ���������
	void manualMode(int c);	        // ������ ����� (�������� �� ������� ���)
	void autoMode(int lum, int c);	// ������������ �����
	void changeRegulator(int c);	// ���� ��������� ���������� �� ������� ���
	//~Lamp();
};

#endif //LAMP_H