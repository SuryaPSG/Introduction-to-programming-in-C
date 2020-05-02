#include "cards.h"

int main(void) {
  card_t t1;
  t1.value=2;
  t1.suit=SPADES;
  assert_card_valid(t1);
  char v='J';
  char s='s';
  card_t t2=card_from_letters(v,s);
  card_t t3=card_from_num(51);
  print_card(t1);
  print_card(t2);
  print_card(t3);
  return 0;
}
