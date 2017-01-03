

class cWindTurbine
{ 
 
private:
   static int total_wind_turbines;
   double PwrMax;
   double QIndMax;
   double QCapMax;
   double WndSpeed;
   double Pwr;
   double Q;
   double QIndCpbl;
   double QCapCpbl;
   double PwrCpbl;
   double GC;
   double PwrSp;
   double QSp;
   int    StopCmd;
   double CosPhi_to_Q(double CosPhi, double Pwr) { return Pwr/sqrt( Pwr*Pwr + Q*Q ); } //inline function
   
public:
   void SetWindSpeed (double);
   void SetStopCmd   (int);
   void SetPwrSp     (double);
   void SetQSp       (double);
   void Execute();
   double GetQCapCpbl  ();
   double GetQIndCpbl  ();
   double GetPwrCpbl   ();
   double GetPwr       ();
   double GetQ         ();
   double GetGC        ();
   cWindTurbine(double,double,double);
   cWindTurbine();
   ~cWindTurbine();
};