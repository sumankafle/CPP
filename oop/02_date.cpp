/**
 * @file date.cpp
 * @brief Simple OOP example demonstrating a Date class and printing its values.
 *
 * This program demonstrates basic object-oriented programming in C++ by
 * grouping related data (day, month, year) into a single class and passing
 * the object by constant reference to a function for printing.
 *
 * @author Suman
 * @date 16/08/2025
 */

#include <iostream>

/**
 * @brief Represents a calendar date.
 *
 * This class models a simple date structure containing
 * day, month, and year values.
 */
class Date
{
public:
    int m_day{};    ///< Day of the month (1–31)
    int m_month{};  ///< Month of the year (1–12)
    int m_year{};   ///< Year (e.g., 2025)

    void print() const
    {
        std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
    }
};

/**
 * @brief Prints a Date object in DD/MM/YYYY format.
 *
 * The Date is passed by const reference to prevent modification
 * and avoid unnecessary copying.
 *
 * @param date The Date object to be printed
 */
void printDate(const Date& date)
{
    std::cout << date.m_day << "/"
              << date.m_month << "/"
              << date.m_year << std::endl;
}

/**
 * @brief Program entry point.
 *
 * Creates a Date object using aggregate initialization
 * and prints it.
 *
 * @return int Exit status (0 indicates success)
 */
int main()
{
    // Create a Date object representing 15 August 2025
    Date today{ 15, 8, 2025 };

    // Print the date
    printDate(today);
    today.print();

    return 0;
}
