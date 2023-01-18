#ifndef IOHANDLING_HPP
#define IOHANDLING_HPP

#include <string>

/**
 * @brief This function is used to convert the card input to an integer.
 * 
 * @param card The symbol of the card (A, 2, 3, ..., 10, J, Q, K)
 * @return The value of card in integer (A = 1, 2 = 2, 3 = 3, ..., 10 = 10, J = 11, Q = 12, K = 13)
 */
int convertCard(std::string card);

/**
 * @brief This function is used to convert an integer to a card symbol (Range 1 - 13)
 * 
 * @param card The card value in integer (A = 1, 2 = 2, 3 = 3, ..., 10 = 10, J = 11, Q = 12, K = 13)
 * @return The symbol of the card according to its value (A, 2, 3, ..., 10, J, Q, K)
 */
std::string convertInt(int card);

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
int* userInput();

/**
 * @brief This function is used to get four cards randomly
 * @return Returns the random cards in a list.
 * @note The random cards will always be valid. 
 */
int* randomInput();

#endif