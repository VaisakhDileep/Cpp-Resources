/*
Created by  : Vaisakh Dileep
Date        : 24, June, 2022
Description : This program helps to understand explicit keyword in C++.
*/

#include<iostream>

using namespace std;

class Video_Game_1
{
public:
    string name;

    Video_Game_1(string name)
        : name {name}
    {
    }
};

void display_video_game_1(const Video_Game_1 &vg1)
{
    cout<<"name: "<<vg1.name<<"\n";
}

class Video_Game_2
{
public:
    string name;

    explicit Video_Game_2(string name)
        : name {name}
    {
    }
};

void display_video_game_2(const Video_Game_2 vg2)
{
    cout<<"name: "<<vg2.name<<"\n";
}

int main()
{
    Video_Game_1 rocket_league = string {"Rocket League"}; // Here the compiler will implicitly convert "string {"Rocket League"}" to a "Video_Game_1" object.

    display_video_game_1(rocket_league);
    cout<<"\n";

    display_video_game_1(string {"Control"}); // Here "string {"Control"}" will be implicitly converted to "Video_Game_1" object.

    // Video_Game_2 galerians = string {"Galerians"}; // Here this will give an error, since we defined the constructor as "explicit", therefore the compiler can't implicitly use this constructor to create the "Video_Game_2" object.

    // display_video_game_1("Grand Theft Auto V"); // This won't work either.

    return 0;
}