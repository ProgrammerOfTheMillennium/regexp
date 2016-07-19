// void set_data()
// parth_data()
// average()
// mean()
// meadian()
// convert_to_json()

#include <iostream>

class MeasureUnit
{
    private:
        std::string date;
        std::string time;
        float air_temp;
        float barometric_press;
        float dew_point;
        float relative_humidity;
        float wind_dir;
        float wind_gust;
        float wind_speed;
    public:
        void SetDate();
        void SetTime();
        void SetAir_Temp();
        void SetBarometric_Press();
        void SetDew_Point();
        void SetRelative_Humidity();
        void SetWind_Dir();
        void SetWind_Gust();
        void SetWind_Speed();

        void GetDate();
        void GetTime();
        void GetAir_Temp();
        void GetBarometric_Press();
        void GetDew_Point();
        void GetRelative_Humidity();
        void GetWind_Dir();
        void GetWind_Gust();
        void GetWind_Speed();
};