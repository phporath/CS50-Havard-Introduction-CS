#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes; // represents the numbers of votes the candidate has
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // its necessary to substract one because the first one is the expression "./plurality"
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{

    for (int i = 0; i < candidate_count; i++)
    {

        if (strcmp(name, candidates[i].name) == 0) // analyse if the strings are the same, if true the output is "0".
        {
            candidates[i].votes = candidates[i].votes + 1; // The candidate receives a vote
            return true;
        }
    }
    
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int winnerVote = 0;
    string winnerName;
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (winnerVote < candidates[i].votes) // look for the candidate that has more votes.
        {
            winnerVote = candidates[i].votes;
            winnerName = candidates[i].name;
        }
        
    }
    
    printf("%s\n", winnerName);
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (winnerVote == candidates[i].votes) // search with there is more than one candidate with the maximum number of votes.
        {
            if (strcmp(winnerName, candidates[i].name) != 0) // it's just for don't repeat the name of the "first winner"
            {
                printf("%s\n", candidates[i].name);
            }
        }
        
    }
    return;
}

