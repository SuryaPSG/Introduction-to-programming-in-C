#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value>=2 && c.value<=VALUE_ACE);
  assert(c.suit>=SPADES && c.suit<=CLUBS);
  return;
}

const char * ranking_to_string(hand_ranking_t r) {
  char * a;
  switch(r){
  case STRAIGHT_FLUSH: a="STRAIGHT_FLUSH" ;break ;
  case FOUR_OF_A_KIND: a="FOUR_OF_A_KIND" ; break ;
  case FULL_HOUSE: a="FULL_HOUSE" ; break ;
  case FLUSH: a="FLUSH" ; break ;
  case STRAIGHT: a="STRAIGHT" ; break ;
  case THREE_OF_A_KIND: a="THREE_OF_A_KIND" ; break ;
  case TWO_PAIR: a="TWO_PAIR" ; break ;
  case PAIR: a="PAIR" ; break ;
  case NOTHING: a="NOTHING" ; break ;
  default: a="???" ; break ;
  }
  return a;
}

char value_letter(card_t c) {
  char x;
  switch(c.value){
  case 2 : x = '2'; break;
  case 3 : x = '3'; break;
  case 4 : x = '4'; break;
  case 5 : x = '5'; break;
  case 6 : x = '6'; break;
  case 7 : x = '7'; break;
  case 8 : x = '8'; break;
  case 9 : x = '9'; break;
  case 10 : x = '0'; break;
  case VALUE_JACK : x = 'J'; break;
  case VALUE_QUEEN : x = 'Q'; break;
  case VALUE_KING : x = 'K'; break;
  case VALUE_ACE : x = 'A'; break;
  default : x = '?'; break;
  }
  return x;
}


char suit_letter(card_t c) {
  char x;
  switch(c.suit){
  case SPADES: x='s' ; break ;
  case HEARTS: x='h' ; break ;
  case DIAMONDS: x='d' ; break;
  case CLUBS: x='c'; break ;
  default: x='?' ; break ;
  }
  return x;
}

void print_card(card_t c) {
  char v=value_letter(c);
  char s=suit_letter(c);
  printf("%c%c",v,s);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let){
  case '2': temp.value=2 ; break;
  case '3': temp.value=3 ; break;
  case '4': temp.value=4 ; break;
  case '5': temp.value=5 ; break;
  case '6': temp.value=6 ; break;
  case '7': temp.value=7 ; break;
  case '8': temp.value=8 ; break;
  case '9': temp.value=9 ; break;
  case '0': temp.value=10 ; break;
  case 'J': temp.value=VALUE_JACK ; break;
  case 'Q': temp.value=VALUE_QUEEN ;break;
  case 'K': temp.value=VALUE_KING ;break;
  case 'A': temp.value=VALUE_ACE ;break;
  }
  switch(suit_let){
  case 's': temp.suit=SPADES ; break ;
  case 'h': temp.suit=HEARTS ; break ;
  case 'd': temp.suit=DIAMONDS ; break ;
  case 'c': temp.suit=CLUBS ; break ;
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  assert(c>=0 && c<52);
  //13 cards from 2 to ACE value 0,1 not possible so add+2 
  temp.value=(c%13)+2;
  //4 suits % 4 will give it
  temp.suit=c/13;
  return temp;
}
