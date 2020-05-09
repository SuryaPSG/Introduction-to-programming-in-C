#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  if(hand==NULL)
    return;
  int n=hand->n_cards;
  if(n==0)
    return;
  card_t **ptr=(hand->cards);
  for(int i=0;i<n;i++){
    print_card(*ptr[i]);
    printf(" ");
  }
  return;
}

int deck_contains(deck_t * d, card_t c) {
  if(d==NULL)
    return 0;
  int n=d->n_cards;
  if(n==0)
    return 0;
  card_t ** ptr=d->cards;
  card_t temp;
  for(int i=0;i<n;i++){
    temp=*ptr[i];
    if(c.value==temp.value && c.suit==temp.suit)
      return 1;
  }
  return 0;
}

void shuffle(deck_t * d){
  if(d==NULL)
    return;
  int n=d->n_cards;
  if(n==0)
    return;
  card_t ** ptr=d->cards;
  card_t temp;
  for(int i=0;i<n;i++){
    int j = i + rand() / (RAND_MAX / (n - i) + 1);
    temp = *ptr[j];
    *ptr[j]=*ptr[i];
    *ptr[i]=temp;
  }
  return;
}

void assert_full_deck(deck_t * d) {
  if(d==NULL)
    return;
  int n=d->n_cards;
  if(n==0)
    return;
  card_t ** ptr=d->cards;
  card_t c1,c2;
  for(int i=0;i<n;i++){
    c1=*ptr[i];
    assert_card_valid(c1);
    for(int j=i+1;j<n;j++){
      c2=*ptr[j];
      assert_card_valid(c2);
      assert(!(c1.value==c2.value && c1.suit == c2.suit));
    }
  }
}
