#include<stdio.h>

int search(int arr[], int n, int num)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(arr[i] == num)
            return i;
    }

    return -1;
}

/*
╭──────────────────────────────────────╮
│              Complexity              │
├──────────────────────────────────────┤
│  Time  : O(N)                        │
│  Space : O(1)                        │
│--------------------------------------│
│  Notes  : Single pass traversal      │
│           No extra data structure    │
╰──────────────────────────────────────╯
*/