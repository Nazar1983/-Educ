#include <math.h>
#include <stdio.h>
#include "wind_turbine.h"

int cWindTurbine::total_wind_turbines = 0;
cWindTurbine::cWindTurbine(double InitPwrMax, double InitQIndMax, double InitQCapMax):
WndSpeed(0), Pwr(0), Q(0), QIndCpbl(0), QCapCpbl(0), PwrCpbl(0), GC(0), PwrSp(0), QSp(0),StopCmd(0) //initialisation of constructor
{
	PwrMax   = PwrCpbl = InitPwrMax;
	QIndCpbl = QIndMax = InitQIndMax;
	QCapCpbl = QCapMax = InitQCapMax;	
	total_wind_turbines ++; //increment total number wind turbines.
	printf("wt created");
}

cWindTurbine::cWindTurbine():
WndSpeed(0), Pwr(0), Q(0), QIndCpbl(0), QCapCpbl(0), PwrCpbl(0), GC(0), PwrSp(0), QSp(0),StopCmd(0) //initialisation of constructor
{
	PwrMax   = PwrCpbl = 1500;
	QIndCpbl = QIndMax = 450;
	QCapCpbl = QCapMax = 450;	
	total_wind_turbines++; //increment total number of wind turbines.
	printf("WT %d created\n", total_wind_turbines);
}


cWindTurbine::~cWindTurbine()
{
    printf("WT %d destroyed\n", total_wind_turbines);
    total_wind_turbines--; //decrement total number of wind turbines.
}

void cWindTurbine::SetWindSpeed (double wspd)   { WndSpeed = wspd;    }
void cWindTurbine::SetStopCmd   (int stop_cmd)  { StopCmd = stop_cmd; }
void cWindTurbine::SetPwrSp     (double pwr_sp) { PwrSp = pwr_sp;     }
void cWindTurbine::SetQSp       (double q_sp)   { QSp = q_sp;         }

double cWindTurbine::GetQCapCpbl  () { return QCapCpbl;  }
double cWindTurbine::GetQIndCpbl  () { return QIndCpbl;  }
double cWindTurbine::GetPwrCpbl   () { return PwrCpbl;   }
double cWindTurbine::GetPwr       () { return Pwr;       }
double cWindTurbine::GetQ         () { return Q;         }
double cWindTurbine::GetGC        () { return GC;        }

void cWindTurbine::Execute ()
{
	//Active Power Regulaton
	if (PwrCpbl > PwrMax)
	{
		PwrCpbl = PwrMax;
	}
		
	PwrSp < PwrCpbl ? Pwr = PwrSp : Pwr = PwrCpbl;
	
	//Reactive Power regulation
	QIndCpbl = -CosPhi_to_Q (0.95, Pwr);
	QCapCpbl = CosPhi_to_Q  (0.95, Pwr);
					
	if (QIndCpbl < -QIndMax)
	{
		QIndCpbl = -QIndMax;
	}
	
	if (QCapCpbl > QCapMax)
	{
		QCapCpbl = QCapMax;
	}
	
	Q = QSp;
	
	if (Q > QCapCpbl)
	{
		Q = QCapCpbl;
	}
	else if (Q < QIndCpbl)
	{
		Q = QIndCpbl;
	}
	
	if (StopCmd)
	{
		GC = 0;
		Pwr = 0;
		Q = 0;
	}
}




int main (void)
{	
	cWindTurbine WindTurbine[10];
	return 0;
}
