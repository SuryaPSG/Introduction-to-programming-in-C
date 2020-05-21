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
void add_card_to(deck_t * deck, card_t c){

  card_t* c1=malloc(sizeof(*c1));

  c1->value = c.value;

  c1->suit = c.suit;

  deck ->cards= realloc(deck->cards,(deck ->n_cards + 1)*sizeof(*deck ->cards));

  deck ->cards[deck ->n_cards]=c1;

  deck ->n_cards ++;

}



card_t * add_empty_card(deck_t * deck){

  card_t* c1=malloc(sizeof(*c1));

  c1->value = 0;

  c1->suit = 0;

  deck ->cards= realloc(deck->cards,(deck ->n_cards + 1)*sizeof(*deck ->cards));

  deck ->cards[deck ->n_cards]=c1;

  deck ->n_cards ++;

  return c1;

}





deck_t * make_deck_exclude(deck_t * excluded_cards){

  deck_t* ans=malloc(sizeof(*ans));

  ans->cards=NULL;

  ans->n_cards=0;

  for(unsigned i=0;i<52;i++){

    card_t c= card_from_num(i);

    if(!deck_contains(excluded_cards,c)) add_card_to(ans,c);

  }

  return ans;

}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {

  deck_t* deck=malloc(sizeof(*deck));

  deck->n_cards=0;

  deck->cards=NULL;

  for (size_t i=0 ; i<n_hands ;i++){

    for(int x=0 ; x<hands[i]->n_cards ;x++){

      deck->cards=realloc(deck->cards,(deck->n_cards+1)*sizeof(*deck->cards));

      deck->cards[deck->n_cards]=hands[i]->cards[x];

      deck->n_cards ++;

    }

  }

  deck_t* deck2=make_deck_exclude(deck);

  free(deck->cards);

  free(deck);

  return deck2 ;

}



void free_deck(deck_t * deck) {

  for(int i=0 ;i<deck->n_cards;i++){

    free(deck->cards[i]);

  }

  free(deck->cards);

  free(deck);

}
