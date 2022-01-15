#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <stdalign.h>

typedef struct PokemonNode {
  //struct for each node in the pokemon list
  //contains pokemon species name, type and primary ability
  //stored as strings
  char name[12];
  char type[17];
  char ability[15];

  struct PokemonNode *next;
} PokemonNode;

typedef struct PlayerNode {
  //struct for each node in the player list
  //contains player name, number of pokemon owned and array of pokemon they own
  //name and pokemon count stored as strings
  //array is an array of pointers to pokemon owned
  
  char p_name[33];
  int owned;
  PokemonNode array[20];
  
  struct PlayerNode *next;
} PlayerNode;

typedef struct Pokedex {
   //pokedex struct
   //contains two pointers
   //one to pokemon list head
   //one to player list head

   PokemonNode *pkmn_head; //struct
   PlayerNode *player_head;//struct

} Pokedex;

PokemonNode* NewPokemonNode(char name[12], char type[17], char ability[15]);
PlayerNode* NewPlayerNode(char name[33]);
PokemonNode* FindPokemon(Pokedex pokedex, char name[12]);
PlayerNode* FindPlayer(Pokedex pokedex, char p_name[33]);
void AddPokemonToList(Pokedex *pokedex, char name[12], char type[17], char ability[15]);
void AddPlayerToList(Pokedex *pokedex, char p_name[33]);
void AddPokemonToPlayer(Pokedex pokedex, char player_name[33], char poke_name[12]);
void ListPokemon(Pokedex pokedex);
void ListPlayers(Pokedex pokedex);
void DisplayPokemonDetails(Pokedex pokedex, char name[12]);
void DisplayPlayerDetails(Pokedex pokedex, char p_name[12]);

int main(void) {
    Pokedex pokedex;
    pokedex.player_head=NULL;
    pokedex.pkmn_head=NULL;

    Pokedex *pokedex_ptr = &pokedex;

    AddPokemonToList(pokedex_ptr, "Absol", "Dark", "Pressure");
    AddPokemonToList(pokedex_ptr, "Absol", "Dark", "Pressure");
    AddPokemonToList(pokedex_ptr, "Gardevoir", "Psychic-Fairy", "Synchronize");
    AddPokemonToList(pokedex_ptr, "Pikachu", "Electric", "Static");
    AddPokemonToList(pokedex_ptr, "Eevee", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "2", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "3", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "4", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "5", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "6", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "7", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "8", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "9", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "10", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "11", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "12", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "13", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "14", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "15", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "16", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "17", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "18", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "19", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "20", "Normal", "Adaptability");
    AddPokemonToList(pokedex_ptr, "21", "Normal", "Adaptability");

    ListPokemon(*pokedex_ptr);

    AddPlayerToList(pokedex_ptr, "Ash");
    AddPlayerToList(pokedex_ptr, "Misty");
    AddPlayerToList(pokedex_ptr, "Misty");
    AddPlayerToList(pokedex_ptr, "Dawn");
    ListPlayers(*pokedex_ptr);

    AddPokemonToPlayer(*pokedex_ptr, "Ash", "notapokemon");
    AddPokemonToPlayer(*pokedex_ptr, "notaplayer", "Pikachu");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "Pikachu");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "2");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "3");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "4");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "5");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "6");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "7");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "8");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "9");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "10");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "11");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "12");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "13");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "14");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "15");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "16");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "17");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "18");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "19");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "20");
    AddPokemonToPlayer(*pokedex_ptr, "Ash", "21");
    //just checking what happens if you try to add too many pokemon to a players list :)
    
    DisplayPokemonDetails(*pokedex_ptr, "notapokemon");
    DisplayPlayerDetails(*pokedex_ptr, "notaplayer");
}

//New Pkmn + Player node functions

PokemonNode* NewPokemonNode(char name[12], char type[17], char ability[15]) {
  //creates a new node and returns a pointer to that node
  PokemonNode *new_node = NULL;
  new_node = malloc(sizeof(PokemonNode));

  if (new_node != NULL)
  {
    //the new node is given the correct attributes
    strcpy(new_node->name, name);
    strcpy(new_node->type, type);
    strcpy(new_node->ability, ability);
    new_node->next=NULL;
  }
  return new_node;
}

PlayerNode* NewPlayerNode(char name[33]) {
  //creates a new node and returns a pointer to that node
  PlayerNode *new_node = NULL;
  new_node = malloc(sizeof(PlayerNode));

  if (new_node != NULL)
  {
    //the new node is given the correct attributes
    strcpy(new_node->p_name, name);
    //pokemon count is set to 0
    new_node->owned=0;
    memset(new_node->array, ' ', sizeof(new_node->array));
    new_node->next=NULL;
  }
  return new_node;
}

//Find Pkmn + Find Player functions

PokemonNode* FindPokemon(Pokedex pokedex, char name[12]) {
  //searches the Pokemon list for name. 
  //If it finds name it returns a pointer to the name’s node otherwise it returns NULL.
  PokemonNode *temp = pokedex.pkmn_head;
  //no search and returns NULL if the list is empty
  if (temp == NULL){
    return NULL;
  }

  //if the head is not NULL then the rest of the list is searched
  //check if current entry is the pokemon we are searching for
  char temp_namea[12];
  strcpy(temp_namea, temp->name);
  //if strcmp(temp_namea, name) returns 0 if the names being compared are the same
  if (strcmp(temp_namea, name)==0)
  {
    //if we find the name being searched for then
    //the function returns the pointer to that node
    return temp;
  }
  //if the next entry is NULL then temp is the final item in the list
  while (temp->next != NULL)
  {
    //if the next entry is not NULL, move on to the next node
    temp = temp->next;

    //check if current entry is the pokemon we are searching for
    char temp_nameb[12];
    strcpy(temp_nameb, temp->name);
    if (strcmp(temp_nameb, name)==0)
    {
      return temp;
    }
  }
  //if the name beign searched for is not found then
  //the function returns NULL
  return NULL;
}

PlayerNode* FindPlayer(Pokedex pokedex, char p_name[33]) {
  //searches the Player list for name. 
  //If it finds name it returns a pointer to the name’s node otherwise it returns NULL.
  PlayerNode *temp = pokedex.player_head;
  //no search and returns NULL if the list is empty
  if (temp == NULL){
    return NULL;
  }

  //if the head is not NULL then the rest of the list is searched
  //check if current entry is the player we are searching for
  char temp_namea[12];
  strcpy(temp_namea, temp->p_name);
  //if strcmp(temp_namea, name) returns 0 if the names being compared are the same
  if (strcmp(temp_namea, p_name)==0)
  {
    //if we find the name being searched for then
    //the function returns the pointer to that node
    return temp;
  }
  //if the next entry is NULL then temp is the final item in the list
  while (temp->next != NULL)
  {
    //if the next entry is not NULL, move on to the next node
    temp = temp->next;

    //check if current entry is the player we are searching for
    char temp_nameb[12];
    strcpy(temp_nameb, temp->p_name);
    if (strcmp(temp_nameb, p_name)==0)
    {
      return temp;
    }
  }
  //if the name being searched for is not found then the function returns NULL
  return NULL;
}

//Add Pkmn + Add Player to list functions

void AddPokemonToList(Pokedex *pokedex, char name[12], char type[17], char ability[15]) {
  //checks to see if name already exists in the Pokemon list. 
  //If it doesn’t it creates a new node and adds it to the list. If the Pokemon already exists it does nothing.

  //checks to see if name already exists
  if (FindPokemon(*pokedex, name)==NULL)
  {
    //---------------
    //creates new node using NewPokemonNode(name, type, ability) function
    //now the function must add the new node to the end of the list
    PokemonNode *new_node = NewPokemonNode(name, type, ability);
    //traverse through the list to find the final node in the list
    PokemonNode *temp = pokedex->pkmn_head;
  
    if (temp != NULL){
      //if the next entry is NULL then temp is the final node in the list
      while (temp->next != NULL)
      {
        //if next entry is not NULL, move onto next node
        temp = temp->next;
      }
      //when the loop breaks, temp will be the final node in the list
      //this is when the new node is added
      //the final node is set to point to the new node
      temp->next = new_node;
      printf("[+] Pokémon (%s) added to dex.\n", name);

    }
    else{
      temp = new_node;
      pokedex->pkmn_head = temp;
      printf("[+] Pokémon (%s) added to dex.\n", name);
    }
    //----------------
  }
  else
    {
      //if pokemon name is already found in the list
      //nothing happens and the pokemon isn't added again
      printf("[!] Pokémon (%s) already exists in list.\n", name);
    }
  //end AddPokemonToList() function
}


void AddPlayerToList(Pokedex *pokedex, char p_name[33]) {
  //checks to see if name already exists in the Player list. 
  //If it doesn’t it creates a new node and adds it to the list. It the player already exists it does nothing.

  //checks to see if name already exists
  if (FindPlayer(*pokedex, p_name)==NULL)
  {    
    //if player name not found then it is added to list
    //creates new node using NewPlayerNode(name) function
    PlayerNode *new_node = NewPlayerNode(p_name);
    
    //now the function must add the new node to the end of the list
    //traverse through the list to find the final node in the list
    PlayerNode *temp = pokedex->player_head;
    
    if (pokedex->player_head==NULL)
    {
      pokedex->player_head = new_node;
      printf("[+] Player (%s) added to list.\n", p_name);
    }

    if (temp != NULL){
      //if the next entry is NULL then temp is the final node in the list
      while (temp->next != NULL)
      {
        //if next entry is not NULL, move onto next node
        temp = temp->next;
      }
      //when the loop breaks, temp will be the final node in the list
      //this is when the new node is added
      //the final node is set to point to the new node
      temp->next = new_node;
      printf("[+] Player (%s) added to list.\n", p_name);
    }
  }
  else
  {
    //if player name is already found in the list
    //nothing happens and the player isn't added again
    printf("[!] Player (%s) already exists in list.\n", p_name);
  }

  //end AddPlayerToList() function
}

//Add obtained pokemon to player 

void AddPokemonToPlayer(Pokedex pokedex, char player_name[33], char poke_name[12]) {
  //Add existing pokemon node to player array and update owned counter
  PlayerNode *player = FindPlayer(pokedex, player_name);
  PokemonNode *pokemon = FindPokemon(pokedex, poke_name);
  if (player!=NULL && pokemon!=NULL){
    if (player->owned!=20){
      player->array[player->owned]=*pokemon;
      printf("%s added to player's (%s) list.\n", pokemon->name, player_name);

      player->owned=player->owned +1;
      printf("%s now has %i Pokémon.\n", player_name, player->owned);
    }
    else{
      printf("Player's (%s) PC is full!\n", player_name);
    } 
  }
  else
  {
    printf("The player or Pokémon was not found.\n");
  }
}

//List Pokemon + Player functions

void ListPokemon(Pokedex pokedex) {
  //outputs a list of names of all Pokemon in the Pokedex
  PokemonNode *temp = pokedex.pkmn_head;
  if (temp!=NULL) {
    printf("\n---Pokémon List---\n");
    while (temp->next != NULL) {
      printf("•%s\n", temp->name);
      temp=temp->next;
    }
    printf("•%s\n", temp->name);
    printf("------------------\n");
    printf("\n");
  }
  else {
    printf("Pokémon list is empty!\n");
  }
}

void ListPlayers(Pokedex pokedex) {
  //outputs a list of names of all players in the Pokedex
  PlayerNode *temp = pokedex.player_head;
  if (temp!=NULL) {
    printf("\n---Player List---\n");
    while (temp->next != NULL) {
      printf("•%s\n", temp->p_name);
      temp=temp->next;
    }
    printf("•%s\n", temp->p_name);
    printf("------------------\n");
    printf("\n");
  }
  else {
    printf("Player list is empty!\n\n");
  }
}

//Display Pokemon + Player details functions

void DisplayPokemonDetails(Pokedex pokedex, char name[12]) {
  //output details of passed pokemon 'name' to screen

  PokemonNode *temp = FindPokemon(pokedex, name);
  if (temp!=NULL) {
    printf("------Pokémon Search------\n");
    printf("Name: %s\n", name);
    printf("Type: %s\n", temp->type);
    printf("Ability: %s\n", temp->ability);
    printf("--------------------------\n\n");
  }
  else
  {
    printf("[!] Pokémon (%s) not found.\n", name);
  }
}

void DisplayPlayerDetails(Pokedex pokedex, char p_name[12]) {
  //output details of passed player 'p_name' to screen
  //include list of all owned pokemon

  PlayerNode *temp = FindPlayer(pokedex, p_name);
  if (temp != NULL){
    printf("-------Player Search-------\n");
    printf("Name: %s\n", p_name);
    printf("Obtained: %i\n", temp->owned);
    for (int i=0; i!=temp->owned; i++){
      printf("•%s\n", temp->array[i].name);
    
    }
    printf("--------------------------\n");
  }
  else {
    printf("[!] Player (%s) not found.\n", p_name);
  }
}