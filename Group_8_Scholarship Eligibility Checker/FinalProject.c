#include <stdio.h>

int isEligibleBS(int continent, int country)
{
    int ssc, hssc, age, income, ielts;
    float score = 0.0;
    char name[30];

    getchar();

    printf("Enter your name:\n");
    fgets(name, sizeof(name), stdin);

    printf("Enter your SSC/O-level marks in percentage:(like 90)\n");
    scanf("%d", &ssc);

    printf("Enter your HSSC/A-level marks in percentage:(like 90)\n");
    scanf("%d", &hssc);

    printf("Enter your age:\n");
    scanf("%d", &age);

    printf("Do you have IELTS?\n");
    printf("1.Yes\n");
    printf("2.No\n");
    scanf("%d", &ielts);

    if (ielts == 1)
    {
        printf("Enter your English score:\n");
        scanf("%f", &score);
    }

    printf("Enter your household monthly income:(In dollars like 2000)\n");
    scanf("%d", &income);

        // 1 = Fully Funded
        // 2 = Partially Funded
        // 3 = Rejected

    int result = 0;
    // Asia
    if (continent == 1)
    {
        // China
        if (country == 1)
        {
            if (ssc >= 85 && hssc >= 85 && age <= 25 && income <= 2000)
            {
                if (ielts == 1 && score >= 6.0)
                {
                    result = 1;
                }
                else
                {
                    result = 3;
                }
            }
            else if (ssc >= 75 && hssc >= 75 && age <= 25 && income <= 3000)
            {
                if (ielts == 1 && score >= 6.0)
                {
                    result = 2;
                }
                else
                {
                    result = 3;
                }
            }
            else
            {
                result = 3;
            }
        }

        // Japan
        else if (country == 2)
        {
            if (ssc >= 90 && hssc >= 90 && age <= 22 && income <= 1500)
            {
                if (ielts == 1 && score >= 6.5)
                {
                    result = 1;
                }
                else
                {
                    result = 3;
                }
            }
            else if (ssc >= 85 && hssc >= 85 && age <= 22 && income <= 2000)
            {
                if (ielts == 1 && score >= 6.0)
                {
                    result = 2;
                }
                else
                {
                    result = 3;
                }
            }
            else
            {
                result = 3;
            }
        }

        // Turkey
        else if (country == 3)
        {
            if (ssc >= 80 && hssc >= 80 && age <= 25 && income <= 2500)
            {
                if (ielts == 1 && score >= 6.0)
                {
                    result = 1;
                }
                else
                {
                    result = 3;
                }
            }
            else if (ssc >= 70 && hssc >= 70 && age <= 25 && income <= 3500)
            {
                if (ielts == 1 && score >= 5.5)
                {
                    result = 2;
                }
                else
                {
                    result = 3;
                }
            }
            else
            {
                result = 3;
            }
        }
    }
//oceania
    else if (continent == 2)
    {
        // Australia
        if (country == 1)
        {
            if (ssc >= 90 && hssc >= 90 && age <= 21 && income <= 1300)
            {
                if (ielts == 1 && score >= 6.5)
                {
                    result = 1;
                }
                else
                {
                    result = 3;
                }
            }
            else if (ssc >= 85 && hssc >= 85 && age <= 21 && income <= 1800)
            {
                if (ielts == 1 && score >= 6.0)
                {
                    result = 2;
                }
                else
                {
                    result = 3;
                }
            }
            else
            {
                result = 3;
            }
        }

        // Newzeland
        else if (country == 2)
        {
            if (ssc >= 85 && hssc >= 85 && age <= 21 && income <= 1500)
            {
                if (ielts == 1 && score >= 6.5)
                {
                    result = 1;
                }
                else
                {
                    result = 3;
                }
            }
            else if (ssc >= 80 && hssc >= 80 && age <= 21 && income <= 1500)
            {
                if (ielts == 1 && score >= 6.0)
                {
                    result = 2;
                }
                else
                {
                    result = 3;
                }
            }
            else
            {
                result = 3;
            }
        }
    }
//europe
    else if (continent == 3)
    {
        // Germany
        if (country == 1)
        {
            if (ssc >= 90 && hssc >= 90 && age <= 23 && income <= 2000)
            {
                if (ielts == 1 && score >= 6.5)
                {
                    result = 1;
                }
                else
                {
                    result = 3;
                }
            }
            else if (ssc >= 80 && hssc >= 80 && age <= 23 && income <= 3000)
            {
                if (ielts == 1 && score >= 6.0)
                {
                    result = 2;
                }
                else
                {
                    result = 3;
                }
            }
            else
            {
                result = 3;
            }
        }

        // France
        else if (country == 2)
        {
            if (ssc >= 90 && hssc >= 90 && age <= 21 && income <= 2200)
            {
                if (ielts == 1 && score >= 6.5)
                {
                    result = 1;
                }
                else
                {
                    result = 3;
                }
            }
            else if (ssc >= 85 && hssc >= 85 && age <= 22 && income <= 2000)
            {
                if (ielts == 1 && score >= 6.0)
                {
                    result = 2;
                }
                else
                {
                    result = 3;
                }
            }
            else
            {
                result = 3;
            }
        }

        // Italy
        else if (country == 3)
        {
            if (ssc >= 80 && hssc >= 80 && age <= 25 && income <= 1500)
            {
                if (ielts == 1 && score >= 6.0)
                {
                    result = 1;
                }
                else
                {
                    result = 3;
                }
            }
            else if (ssc >= 70 && hssc >= 70 && age <= 25 && income <= 1800)
            {
                if (ielts == 1 && score >= 5.5)
                {
                    result = 2;
                }
                else
                {
                    result = 3;
                }
            }
            else
            {
                result = 3;
            }
        }
    }
// north america
    else if (continent == 4)
    {
        // Canada
        if (country == 1)
        {
            if (ssc >= 90 && hssc >= 90 && age <= 21 && income <= 3000)
            {
                if (ielts == 1 && score >= 6.5)
                {
                    result = 1;
                }
                else
                {
                    result = 3;
                }
            }
            else if (ssc >= 85 && hssc >= 85 && age <= 21 && income <= 3500)
            {
                if (ielts == 1 && score >= 6.0)
                {
                    result = 2;
                }
                else
                {
                    result = 3;
                }
            }
            else
            {
                result = 3;
            }
        }

        // Usa
        else if (country == 2)
        {
            if (ssc >= 90 && hssc >= 90 && age <= 22 && income <= 2500)
            {
                if (ielts == 1 && score >= 6.5)
                {
                    result = 1;
                }
                else
                {
                    result = 3;
                }
            }
            else if (ssc >= 85 && hssc >= 85 && age <= 22 && income <= 2000)
            {
                if (ielts == 1 && score >= 6.0)
                {
                    result = 2;
                }
                else
                {
                    result = 3;
                }
            }
            else
            {
                result = 3;
            }
        }
    }
    printf("======================================\n");
    printf("Your Information :\n");
    printf("======================================\n");

    printf("Name:                %s", name);
    printf("Age:                 %d\n", age);
    printf("SSC result:          %d\n", ssc);
    printf("HSSC result:         %d\n", hssc);

    if (ielts == 1)
    {
        printf("IELTS score:         %.1f\n", score);
    }
    else
    {
        printf("IELTS:               No\n");
    }

    printf("Family income:       %d\n", income);
    if (result == 3)
    {
        printf("======================================\n");
        printf("Scholarship Eligiblity Result :\n");
        printf("======================================\n");
        printf("\n");
        printf("Unfortunately you are not eligible for the scholarship:\n");
        printf("\n");
        printf("======================================\n");
        printf("Reason(s) of Rejection:\n");
        printf("======================================\n");
        // Asia
        if (continent == 1)
        {
            // China
            if (country == 1)
            {
                if (ssc < 75 || hssc < 75)
                {
                    printf("Reason: Your SSC/HSSC results do not meet the required percentage.\n");
                }

                if (age > 25)
                {
                    printf("Reason: Your age does not meet the required criteria.\n");
                }

                if (income > 3000)
                {
                    printf("Reason: Your family income does not meet the required criteria.\n");
                }

                if (ielts != 1 || score < 6.0)
                {
                    printf("Reason: Your IELTS score does not meet the required criteria.\n");
                }
            }

            // Japan
            if (country == 2)
            {
                if (ssc < 85 || hssc < 85)
                {
                    printf("Reason: Your SSC/HSSC results do not meet the required percentage.\n");
                }

                if (age > 22)
                {
                    printf("Reason: Your age does not meet the required criteria.\n");
                }

                if (income > 2000)
                {
                    printf("Reason: Your family income does not meet the required criteria.\n");
                }

                if (ielts != 1 || score < 6.0)
                {
                    printf("Reason: Your IELTS score does not meet the required criteria.\n");
                }
            }

            // Turkey
            if (country == 3)
            {
                if (ssc < 70 || hssc < 70)
                {
                    printf("Reason: Your SSC/HSSC results do not meet the required percentage.\n");
                }

                if (age > 25)
                {
                    printf("Reason: Your age does not meet the required criteria.\n");
                }

                if (income > 3500)
                {
                    printf("Reason: Your family income does not meet the required criteria.\n");
                }

                if (ielts != 1 || score < 5.5)
                {
                    printf("Reason: Your IELTS score does not meet the required criteria.\n");
                }
            }
        }


        // Ocenia
        if (continent == 2)
        {
            //Australia
            if (country == 1)
            {
                if (ssc < 85 || hssc < 85)
                {
                    printf("Reason: Your SSC/HSSC results do not meet the required percentage.\n");
                }

                if (age > 21)
                {
                    printf("Reason: Your age does not meet the required criteria.\n");
                }

                if (income > 1800)
                {
                    printf("Reason: Your family income does not meet the required criteria.\n");
                }

                if (ielts != 1 || score < 6.0)
                {
                    printf("Reason: Your IELTS score does not meet the required criteria.\n");
                }
            }

            // newzeland
            if (country == 2)
            {
                if (ssc < 80 || hssc < 80)
                {
                    printf("Reason: Your SSC/HSSC results do not meet the required percentage.\n");
                }

                if (age > 21)
                {
                    printf("Reason: Your age does not meet the required criteria.\n");
                }

                if (income > 1500)
                {
                    printf("Reason: Your family income does not meet the required criteria.\n");
                }

                if (ielts != 1 || score < 6.0)
                {
                    printf("Reason: Your IELTS score does not meet the required criteria.\n");
                }
            }
        }


        //Europe
        if (continent == 3)
        {
            // Germany
            if (country == 1)
            {
                if (ssc < 80 || hssc < 80)
                {
                    printf("Reason: Your SSC/HSSC results do not meet the required percentage.\n");
                }

                if (age > 23)
                {
                    printf("Reason: Your age does not meet the required criteria.\n");
                }

                if (income > 3000)
                {
                    printf("Reason: Your family income does not meet the required criteria.\n");
                }

                if (ielts != 1 || score < 6.0)
                {
                    printf("Reason: Your IELTS score does not meet the required criteria.\n");
                }
            }

            // france
            if (country == 2)
            {
                if (ssc < 85 || hssc < 85)
                {
                    printf("Reason: Your SSC/HSSC results do not meet the required percentage.\n");
                }

                if (age > 22)
                {
                    printf("Reason: Your age does not meet the required criteria.\n");
                }

                if (income > 2000)
                {
                    printf("Reason: Your family income does not meet the required criteria.\n");
                }

                if (ielts != 1 || score < 6.0)
                {
                    printf("Reason: Your IELTS score does not meet the required criteria.\n");
                }
            }

            // Italy
            if (country == 3)
            {
                if (ssc < 70 || hssc < 70)
                {
                    printf("Reason: Your SSC/HSSC results do not meet the required percentage.\n");
                }

                if (age > 25)
                {
                    printf("Reason: Your age does not meet the required criteria.\n");
                }

                if (income > 1800)
                {
                    printf("Reason: Your family income does not meet the required criteria.\n");
                }

                if (ielts != 1 || score < 5.5)
                {
                    printf("Reason: Your IELTS score does not meet the required criteria.\n");
                }
            }
        }


        // north america
        if (continent == 4)
        {
            // Canada
            if (country == 1)
            {
                if (ssc < 85 || hssc < 85)
                {
                    printf("Reason: Your SSC/HSSC results do not meet the required percentage.\n");
                }

                if (age > 21)
                {
                    printf("Reason: Your age does not meet the required criteria.\n");
                }

                if (income > 3500)
                {
                    printf("Reason: Your family income does not meet the required criteria.\n");
                }

                if (ielts != 1 || score < 6.0)
                {
                    printf("Reason: Your IELTS score does not meet the required criteria.\n");
                }
            }

            // Usa
            if (country == 2)
            {
                if (ssc < 85 || hssc < 85)
                {
                    printf("Reason: Your SSC/HSSC results do not meet the required percentage.\n");
                }

                if (age > 22)
                {
                    printf("Reason: Your age does not meet the required criteria.\n");
                }

                if (income > 2500)
                {
                    printf("Reason: Your family income does not meet the required criteria.\n");
                }

                if (ielts != 1 || score < 6.0)
                {
                    printf("Reason: Your IELTS score does not meet the required criteria.\n");
                }
            }
        }
    }

    return result;
}


int main()
{
    printf("======================================\n");
    printf("\n");
    printf("WELLCOME TO:\n");
    printf("SCHOLARSHIP ELIGIBLITY SYSTEM: \n");
    printf("\n");
    printf("======================================\n");
    printf("\n");


    int continent;

    printf("Which continent are you looking to study in?\n");
    printf("1.Asia\n");
    printf("2.Oceania\n");
    printf("3.Europe\n");
    printf("4.North America\n");

    scanf("%d", &continent);

    if (continent < 1 || continent > 4)
    {
        printf("INVALID OPTION:\n");
        printf("TRY AGAIN:\n");
        return 1;
    }


    printf("Select your preferred study destination:\n");

    int country = 0;


    if (continent == 1)
    {
        printf("1.China\n");
        printf("2.Japan\n");
        printf("3.Turkey\n");

        scanf("%d", &country);

        if (country < 1 || country > 3)
        {
            printf("INVALID COUNTRY OPTION:\n");
            return 1;
        }
    }


    else if (continent == 2)
    {
        printf("1.Australia\n");
        printf("2.Newzeland\n");

        scanf("%d", &country);

        if (country < 1 || country > 2)
        {
            printf("INVALID COUNTRY OPTION:\n");
            return 1;
        }
    }


    else if (continent == 3)
    {
        printf("1.Germany\n");
        printf("2.France\n");
        printf("3.Italy\n");

        scanf("%d", &country);

        if (country < 1 || country > 3)
        {
            printf("INVALID COUNTRY OPTION:\n");
            return 1;
        }
    }


    else if (continent == 4)
    {
        printf("1.Canada\n");
        printf("2.USA\n");

        scanf("%d", &country);

        if (country < 1 || country > 2)
        {
            printf("INVALID COUNTRY OPTION:\n");
            return 1;
        }
    }


    int result;

    result = isEligibleBS(continent, country);

    if (result == 1)
    {
        printf("======================================\n");
        printf("Scholarship Eligiblity Result :\n");
        printf("======================================\n");
        printf("\n");
        printf("Congratulations!\n");
        printf("You are eligible for a Fully Funded Scholarship.\n");
        printf("Your excellence earned you the full opportunity.\n");
    }


    else if (result == 2)
    {
         printf("======================================\n");
         printf("Scholarship Eligiblity Result :\n");
         printf("======================================\n");
         printf("\n");
         printf("Congratulations!\n");
         printf("You are eligible for a Partially Funded Scholarship.\n");
         printf("A strong start to a bright future.\n");
    }

    return 0;
}

