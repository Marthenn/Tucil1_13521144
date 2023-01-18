#ifndef IOHANDLING_HPP
#define IOHANDLING_HPP

#include <string>

/**
 * @brief This function is used to validate the card input.
 * @param card The card numbers to be validated (A, 2, 3, ..., 10, J, Q, K)
 * @return Returns true if the input is a card from a poker deck, false otherwise.
 */
bool cardValidation(std::string card);

/**
 * @brief This function is used to validate the user input.
 * @param input The input string to be validated.
 * @return Returns true if the input is valid, false otherwise.
*/
bool inputValidation(std::string input);

/**
 * @brief This function is used to get the user input for the cards.
 * @return Returns the user input in a list.
 * @note The user input is validated before returning.
*/
int userInput();

/**
 * @brief This function is used to get four cards randomly
 * @return Returns the random cards in a list.
 * @note The random cards will always be valid. 
 */
int randomInput();

#endif