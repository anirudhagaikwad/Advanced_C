
/* Implement a voting system using a union to store different vote types.
The voting system can accept votes as either integers or characters.
*/

#include <stdio.h>

// Union definition for Vote
union Vote {
    int candidateID;
    char partySymbol;
};

int main() {
    // Creating a vote union
    union Vote vote;

    // Accepting an integer vote
    vote.candidateID = 1;

    // Displaying the integer vote
    printf("Candidate ID: %d\n", vote.candidateID);

    // Accepting a character vote
    vote.partySymbol = 'A';

    // Displaying the character vote
    printf("Party Symbol: %c\n", vote.partySymbol);

    return 0;
}
/*
This program implements a voting system using a union to store different types of votes.
The union Vote can store either an integer candidate ID or a character party symbol.
The program creates an instance of the union, accepts an integer vote, displays it, accepts a character vote, and displays it.
*/
