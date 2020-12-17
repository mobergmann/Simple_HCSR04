#include <Arduino.h>

#include "Simple_HCSR04.h"


#pragma region Mesurement

Simple_HCSR04::Mesurement::Mesurement(unsigned long mesurement)
    : m_mesurement(mesurement) {}


#pragma region Mesurement getter

unsigned long Simple_HCSR04::Mesurement::mm() const
{
    return this->m_mesurement * 10;
}

unsigned long Simple_HCSR04::Mesurement::cm() const
{
    return this->m_mesurement;
}

float Simple_HCSR04::Mesurement::dm() const
{
    return this->m_mesurement / 10;
}

float Simple_HCSR04::Mesurement::m() const
{
    return this->m_mesurement / 100;
}

#pragma endregion

#pragma endregion


#pragma region Simple_HCSR04

Simple_HCSR04::Simple_HCSR04(const short echo_pin, const short trig_pin)
    : ECHO_PIN(echo_pin), TRIG_PIN(trig_pin)
{
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIG_PIN, OUTPUT);
}

#pragma region Simple_HCSR04 getter

short Simple_HCSR04::getEchoPin() const
{
    return this->ECHO_PIN;
}

short Simple_HCSR04::getTrigPin() const
{
    return this->TRIG_PIN;
}

#pragma endregion

Simple_HCSR04::Mesurement* Simple_HCSR04::mesure()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    unsigned long duration = pulseIn(ECHO_PIN, HIGH);
    unsigned long distance = duration * 0.034 / 2;

    return new Simple_HCSR04::Mesurement(distance);
}

#pragma endregion
