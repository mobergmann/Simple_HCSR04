#ifndef HCSR04_H_
#define HCSR04_H_

#include <Arduino.h>

/**
 * @brief a simple wrapper for the HC-SR04 Module.
 *
 */
class Simple_HCSR04
{
private:
    /// private constructor, souldn't be used.
    Simple_HCSR04();

    const short ECHO_PIN; /// the echo pin
    const short TRIG_PIN; /// the trig pin

public:
    /**
     * @brief a simple wrapper for holding an unsigned long.
     *
     */
    class Mesurement
    {
    private:
        /// private constructor, souldn't be used.
        Mesurement();

        const unsigned long m_mesurement; /// the mesuret distance

    public:
        /**
         * @brief Construct a new Simple_HCSR04::Mesurement::Mesurement object from a given number.
         * The given number should be provided in centimertes in order for a right conversion.
         *
         * @param mesurement distance.
         */
        Mesurement(unsigned long mesurement);

        /**
         * @brief mesurement in millimeters.
         *
         * @return unsigned long
         */
        unsigned long mm() const;

        /**
         * @brief mesurement in centimeters.
         *
         * @return unsigned long
         */
        unsigned long cm() const;

        /**
         * @brief mesurement in decimeters.
         *
         * @return float
         */
        float    dm() const;

        /**
         * @brief mesurement in meters.
         *
         * @return float
         */
        float    m() const;

    };

    /**
     * @brief Construct a new Simple_HCSR04::Simple_HCSR04 object.
     * Also sets the pin mode.
     *
     * @param echo_pin Echo pin on the microcontroller
     * @param trig_pin Trig pin on the microcontroller
     */
    Simple_HCSR04(const short echo_pin, const short trig_pin);

    /**
     * @brief echo pin
     *
     * @return short
     */
    short getEchoPin() const;

    /**
     * @brief trig pin
     *
     * @return short
     */
    short getTrigPin() const;

    /**
     * @brief mesures the time a send soundwafe needs and calculates the distance.
     * This function needs at least 12 milliseconds to execute.
     *
     * @return Simple_HCSR04::Mesurement*
     */
    Mesurement* mesure();

};

#endif
