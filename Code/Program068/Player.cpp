#include "Player.hpp"

Player::Player()
    : player_name {"player"}, player_xp {0}
{
}

Player::~Player()
{
}

void Player::set_player_name(string player_name)
{
    this->player_name = player_name;
}

void Player::set_player_xp(int player_xp)
{
    this->player_xp = player_xp;
}

string Player::get_player_name()
{
    return player_name;
}

int Player::get_player_xp()
{
    return player_xp;
}