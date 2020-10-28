for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

// Record preference if vote is valid
//bool vote(int voter, int rank, string name);
bool vote(int voter, int rank, string name)
{
    for(int i = 0; i < voter_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] == i;
            return true;
        }
    }
    return false;
}