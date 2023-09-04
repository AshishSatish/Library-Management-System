#include <stdio.h> 
#define MAX_CANDIDATES 5 
void castVote(int votes[], int candidateCount) { 
 int candidateNumber; 
 printf("\n1 : ASHISH\n2 : RUSHIKESH\n3 : RITESH\n4 : VIKAS\n"); 
 printf("Enter the candidate number you want to vote for (1-%d): ", candidateCount); 
 scanf("%d", &candidateNumber); 
 // Validate the candidate number 
 if (candidateNumber < 1 || candidateNumber > candidateCount) { 
 printf("Invalid candidate number. Please try again.\n"); 
 return; 
 } 
 votes[candidateNumber - 1]++; 
 printf("Your vote has been cast for candidate number %d\n", candidateNumber); 
} 
void displayResults(int votes[], int candidateCount) { 
 printf("VoƟng Results:\n"); 
 for (int i = 0; i < candidateCount; i++) { 
 printf("Candidate %d: %d votes\n", i + 1, votes[i]); 
 } 
} 
void displayWinner(int votes[], int candidateCount) { 
 if(votes[0]>votes[1] && votes[0]>votes[2] && votes[0]>votes[3] ) 
 printf("Ashish is the winner of the voƟng system");
 if(votes[1]>votes[0] && votes[1]>votes[2] && votes[1]>votes[3] ) 
 printf("Rushikesh is the winner of the voƟng system");
 if(votes[2]>votes[1] && votes[2]>votes[0] && votes[2]>votes[3] ) 
 printf("Ritesh is the winner of the voƟng system");
 if(votes[3]>votes[1] && votes[3]>votes[2] && votes[3]>votes[0] ) 
 printf("Vikas is the winner of the voƟng system");
} 
int main() { 
 int candidateCount = 4; 
 int votes[MAX_CANDIDATES] = {0}; 
 int choice; 
 while (1) { 
 printf("\n-- VoƟng System Menu --\n"); 
 printf("1. Cast Vote\n"); 
 printf("2. Display Results\n"); 
 printf("3. Exit\n"); 
 printf("Enter your choice: ");
 scanf("%d", &choice); 
 switch (choice) { 
 case 1: 
 castVote(votes, candidateCount); 
 break; 
 case 2: 
 displayResults(votes, candidateCount); 
 break; 
 case 3: 
 displayWinner(votes, candidateCount); 
 printf("\nExiƟng the program. Goodbye!\n"); 
 return 0; 
 default: 
 printf("\nInvalid choice. Please try again.\n"); 
 } 
 } 
 return 0; 
} 