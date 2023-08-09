

s32 Map(s32 Copy_s32IN, s32 Copy_s32INmin, s32 Copy_s32INmax, s32 Copy_s32OUTmin, s32 Copy_s32OUTmax)
{
    return ((((Copy_s32IN - Copy_s32INmin)*(Copy_s32OUTmax - Copy_s32OUTmin))/(Copy_s32INmax - Copy_s32INmin)) + Copy_s32OUTmin);
}