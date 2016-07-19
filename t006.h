// float set_data()
// parth_data()
// average()
// mean()
// meadian()
// convert_to_json()

#include <iostream>

struct MeasureUnit
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

        float GetDate();
        float GetTime();
        float GetAir_Temp();
        float GetBarometric_Press();
        float GetDew_Point();
        float GetRelative_Humidity();
        float GetWind_Dir();
        float GetWind_Gust();
        float GetWind_Speed();
};

