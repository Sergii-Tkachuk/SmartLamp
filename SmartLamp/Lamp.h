#ifndef LAMP_H
#define LAMP_H

class Lamp
{
private:
	bool m_power;     // стан електромережі
	bool m_mode;      // режим регулювання	
	bool m_signal;    // сигнал перегрівання
	int m_regulation; // положення регулятора
	int m_temperature;// температура плафона

	void temperatureCalculation(int celsius);// обчислення температури
	void overheating();                      // перевірка перегріву

public:
	//Lamp();                       // встановлює початкові значення
	void setOff();					// вимикання
	void manualMode(int c);	        // ручний режим (вмикання на заданий час)
	void autoMode(int lum, int c);	// автоматичний режим
	void changeRegulator(int c);	// зміна положення регулятора на заданий час
	//~Lamp();
};

#endif //LAMP_H