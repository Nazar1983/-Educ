

class cWindParkController
{ 

private:
   cWindTurbine *WindTurbines;
   int NumberOfWindTurbines;
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
   //wind park control
   void SetStopCmd     (int);
   void SetPwrSp       (double);
   void SetQMode       (double);
   void SetQSp         (double);
   void SetPowerFactor (double);

   //wind turbine communication   
   void SetWTQSp       (int, double);
   void SetWTPSp       (int, double);
   void SetWTStopCmd   (int, double);
   void GetWTQ         (int, double);
   void GetWTPwr       (int, double);
   void GetWTGCStatus  (int, double);

   void Execute();

   cWindPark();
   ~cWindTurbine();
};