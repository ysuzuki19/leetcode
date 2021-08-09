class Solution {
public:
  double angleClock(int hour, int minutes) {
    double hAngle, mAngle;
    mAngle = (minutes*360.0/60.0);
    hAngle = (hour*360.0/12.0) + (mAngle/12.0);
    return min(abs(hAngle - mAngle), abs(abs(hAngle - mAngle) - 360.0));
  }
};