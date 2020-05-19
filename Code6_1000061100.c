/* Maria Maldonado 1000061100 */
/* This is an edit practice. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SockLib.h"

#define MAX_DRAWERS 10

int NumDrawers;

void DisplayMyDresser(SockDrawer Dresser[]);
void PutOnMySocks(SockDrawer Dresser[]);
void PutAwayMySocks(SockDrawer Dresser[]);
void CreateDresser(SockDrawer *MyDresser, int DrawerID);
int GetNumDrawers();
void SortMySocks(SockDrawer Dresser[]);

int DrawerIDCompare(const void *a, const void *b);
int NumberofSocksCompare(const void *a, const void *b);
int MaxCapacityCompare(const void *a, const void *b);
int SockColorCompare(const void *a, const void *b);

void DisplayMyDresser(SockDrawer Dresser[])
{
    printf("\n\nMy Dresser\n\n");
    int i;
    for (i=0; i<NumDrawers; i++)
    {
        printf("\nDrawer %d has %d %s socks and can hold up to %d socks\n",
        Dresser[i].DrawerID, Dresser[i].NumberofSocks, Dresser[i].SockColor,
        Dresser[i].MaxDrawerCapacity);
    }
}

void PutAwayMySocks(SockDrawer Dresser[])
{
    int DrawerID, HowMany;
    printf("\n\nWhich drawer are you putting socks into? ");
    scanf("%d", &DrawerID);
    DrawerID = --DrawerID;
    if (DrawerID < 0 || DrawerID >= NumDrawers)
    {
        printf("\n\nThat's none of your drawers!!");
        return;
    }
    printf("\n\nHow many socks are you putting away? ");
    scanf("%d", &HowMany);
    if (HowMany > Dresser[DrawerID].MaxDrawerCapacity)
    {
        printf("\n\n%d socks fit in the drawer and %d fell on the floor\n",
        Dresser[DrawerID].MaxDrawerCapacity, (HowMany - Dresser[DrawerID].MaxDrawerCapacity));
        Dresser[DrawerID].NumberofSocks = HowMany - Dresser[DrawerID].MaxDrawerCapacity;
        Dresser[DrawerID].NumberofSocks = Dresser[DrawerID].MaxDrawerCapacity;
    }
    else
    {
        Dresser[DrawerID].NumberofSocks = HowMany + Dresser[DrawerID].NumberofSocks;
    }
}

void PutOnMySocks(SockDrawer Dresser[])
{
    int DrawerID, HowMany;
    printf("\n\nWhich drawer do you want to get socks from? ");
    scanf("%d", &DrawerID);
    DrawerID = --DrawerID;
    if (DrawerID < 0 || DrawerID >= NumDrawers)
    {
        printf("\n\nThat's none of your drawers!!");
        return;
    }
    printf("\n\nHow many socks are you getting out? ");
    scanf("%d", &HowMany);
    if (HowMany > Dresser[DrawerID].NumberofSocks)
    {
        printf("\n\nYou don't have that many socks!! You only get %d socks.\n",
        Dresser[DrawerID].NumberofSocks);
        Dresser[DrawerID].NumberofSocks = 0;
    }
    else
    {
        Dresser[DrawerID].NumberofSocks = Dresser[DrawerID].NumberofSocks - HowMany;
    }
}

void CreateDresser(SockDrawer *MyDresser, int DrawerID)
{
    MyDresser->DrawerID = ++DrawerID;
    printf("\nHow many total socks will fit in Drawer %d? ", MyDresser->DrawerID);
    scanf("%d", &MyDresser->MaxDrawerCapacity);
    printf("\nHow many socks are you putting in Drawer %d? ", MyDresser->DrawerID);
    scanf("%d", &MyDresser->NumberofSocks);
    getchar();
    if ((*MyDresser).NumberofSocks > (*MyDresser).MaxDrawerCapacity)
    {

        printf("\n\n%d socks fit in the drawer and %d fell on the floor\n\n",
        (*MyDresser).MaxDrawerCapacity,
        ((*MyDresser).NumberofSocks - (*MyDresser).MaxDrawerCapacity));
        (*MyDresser).NumberofSocks = (*MyDresser).MaxDrawerCapacity;
    }
    printf("\nWhat color are the socks in drawer %d? ", (*MyDresser).DrawerID);
    fgets((*MyDresser).SockColor, 10, stdin);
    ((*MyDresser).SockColor)[strlen((*MyDresser).SockColor)-1] = '\0';

}

int GetNumDrawers()
{
    do
    {
        printf("\nHow many drawers does your dresser have? (1-10) ");
        scanf("%d", &NumDrawers);
        if (NumDrawers == 0)
        {
            return 0;
        }
        if (NumDrawers < 0 || NumDrawers > 10)
        {
            printf("\nNumber of drawers must be between 1 and 10.\n\nPlease reenter.\n");
        }
    } while(NumDrawers < 0 || NumDrawers > 10);
    return 1;
}

void SortMySocks(SockDrawer Dresser[])
{
    int Choice;
    int (*CompareFunctionPtrArray[4])(const void *, const void *) =
    {DrawerIDCompare, NumberofSocksCompare, MaxCapacityCompare, SockColorCompare};
    printf("\nDo you want to sort by?\n\n");
    printf("\n0. Changed my mind - don't want to sort\n");
    printf("1. Drawer ID?\n");
    printf("2. Number of socks in drawer?\n");
    printf("3. Max capacity of the drawers?\n");
    printf("4. Sock color?\n\n");
    printf("\nChoice : ");
    scanf("%d", &Choice);

    if (Choice == 0)
    {
        printf("Your sock drawer is a mess!");
        return;
    }
    else
    {
        qsort(Dresser, MAX_DRAWERS, sizeof(SockDrawer),
        (CompareFunctionPtrArray[Choice-1]));
    }
}


int main(void)
{
    enum SockAction
    {
        RemoveSocks=1, AddSocks, DisplayDresser, SortSocks
    };

    SockDrawer Dresser[10];
    int Choice;

    if (GetNumDrawers() == 0)
    {
        return 0;
    }

    int i;
    for (i = 0; i < NumDrawers; i++)
    {
        CreateDresser(&Dresser[i], i);
    }

    do
    {
        printf("\n\nWhat do you need to do?\n\n");
        printf("\n0. Don't have socks!!\n");
        printf("\n1. Take socks out of a drawer?\n");
        printf("\n2. Put more socks in a drawer?\n");
        printf("\n3. Display dresser\n");
        printf("\n4. Sort socks\n\n");
        printf("\nChoice : ");
        scanf("%d", &Choice);

        switch (Choice)
        {
            case RemoveSocks:
                PutOnMySocks( Dresser);
                DisplayMyDresser( Dresser);
                break;
            case AddSocks:
                PutAwayMySocks( Dresser);
                DisplayMyDresser( Dresser);
                break;
            case DisplayDresser:
                DisplayMyDresser ( Dresser);
                break;
            case SortSocks:
                SortMySocks( Dresser);
                DisplayMyDresser( Dresser);
                break;
            default:
                printf("\nTime to do laundry\n\n");
                break;
        }
    } while(Choice != 0);
return 0;
}
