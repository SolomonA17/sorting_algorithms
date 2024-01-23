#ifndef _DECK_H_
#define _DECK_H_

/**
* enum kind_e - categorization of the card's suit
*
* @SPADE: 0, representing spades
* @HEART: 1, representing hearts
* @CLUB: 2, representing clubs
* @DIAMOND: 3, representing diamonds
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
* struct card_s - depiction of a card
* @value: The value of the card, ranging from "Ace" to "King"
* @kind: The category or kind of the card
*/
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
* struct deck_node_s - Deck of cards
*
* @card: Pointer to the card
* @prev: Pointer to the previous node
* @next: Pointer to the next node
*/
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* _DECK_H_ */

