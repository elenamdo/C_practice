/* Maria Maldonado 1000061100 */

#include "SockLib.h"

int DrawerIDCompare(const void *a, const void *b)
{
	if (((SockDrawer*)a)->DrawerID < ((SockDrawer*)b)->DrawerID)
    return (-1);
  else if (((SockDrawer*)a)->DrawerID > ((SockDrawer*)b)->DrawerID)
    return (1);
  else
    return (0);
}

int NumberofSocksCompare(const void *a, const void *b)
{
  if (((SockDrawer*)a)->NumberofSocks < ((SockDrawer*)b)->NumberofSocks)
    return (-1);
  else if (((SockDrawer*)a)->NumberofSocks > ((SockDrawer*)b)->NumberofSocks)
    return (1);
  else
    return (0);
}

int MaxCapacityCompare(const void *a, const void *b)
{
  if (((SockDrawer*)a)->MaxDrawerCapacity < ((SockDrawer*)b)->MaxDrawerCapacity)
    return (-1);
  else if (((SockDrawer*)a)->MaxDrawerCapacity > ((SockDrawer*)b)->MaxDrawerCapacity)
    return (1);
  else
    return (0);
}

int SockColorCompare(const void *a, const void *b)
{
	return (strcmp(((SockDrawer*)a)->SockColor, ((SockDrawer*)b)->SockColor));
}
