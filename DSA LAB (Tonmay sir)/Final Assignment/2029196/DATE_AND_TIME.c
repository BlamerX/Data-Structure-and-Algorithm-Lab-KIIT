int TimeAndDate()
{
    time_t t;
    time(&t);
    printf("%s", ctime(&t));
    return 0;
}