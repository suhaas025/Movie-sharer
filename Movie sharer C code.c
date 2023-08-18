#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char* account(int i, int acc[3], int age[3], char email[3][20], char pw[3][10], char name[3][20], char genre[5][15]);
void movielist(int unum, char movie[17][50], char desc[17][1000], double cine[17],  char comedy[5][50], char thriller[3][50], char animation[3][50], char action[3][50], char scifi[3][50]);
void help(int unum);
void browse(int unum, char movie[17][50], char desc[17][1000]);
void recommend(int unum,char movie[17][50],char desc[17][1000], double cine[17]);
void sort(); 
void mshare(char uugenre[3][50], char movie[17][50], char comedy[5][50], char thriller[3][50], char animation[3][50], char action[3][50], char scifi[3][50]);
void ratingreview(int unum,double rating[17],char review[17][1000],char movie[17][50]);
void playlist(int unum, char ugenre[3][50], char uugenre[3][50], char comedy[5][50], char thriller[3][50], char animation[3][50], char action[3][50], char scifi[3][50]);
void exit();

int main()
{
    int age[3], acc[3];
    char name[3][20], email[3][20], pw[3][10];
    int i, found, a, b, unum, ans, ans1, ans2, ans3, logout, o;
    char upw[0], n[0];
    char ugenre[3][50], uugenre[3][50];
    double rating[17], cine[17]; 
    char review[17][1000], movie[17][50], desc[17][1000];
    char R1[20], R2[20], R3[20];
    char genre[5][15]={"COMEDY", "THRILLER", "ANIMATION", "ACTION", "SCIENCEFICTION"};
    int T1=0, T2=0, T3=0, svar, ssvar, smovie, sm;
    char comedy[5][50], thriller[3][50], animation[3][50], action[3][50], scifi[3][50];
    printf ("\t\tWelcome to Moviesharer! \nKindly create an account to avail our services");
    for (i=0; i<3; i++)
    {
        strcpy(ugenre[i],account(i, acc, age, email, pw, name, genre));
      printf("%s",ugenre[i]);
    }
    do 
    {
        found=0;
        do 
        {
            printf ("\n----------------------------------------------------------------------");
            printf("\n\t\t\tLOG IN");
            printf("\nWe request you to enter your details and log in to your account");
            printf ("\n----------------------------------------------------------------------");
            printf("\nEnter your account number: ");
            scanf("%d", &unum);
            if (unum==1||unum==2||unum==3)
            {
                printf("Enter your password: ");
                scanf("%s",&upw[0]);
                if (pw[unum-1][10]==upw[0])
                {
                    printf("\nYou have successfully logged in");
                    found=1;
                    printf("\nWelcome to Moviesharer - Your all in-one-ticket to cinemetropolis!");
                    printf("\nYou will now be taken to the Homepage where you can select what you would like to do next");
                    movielist(unum, movie, desc, cine, comedy, thriller, animation, action, scifi);
                    do
                    {
                        printf ("\n----------------------------------------------------------------------");
                        printf("\n\t\t\tHOME PAGE\n");
                        printf("\nEnter the required option number: \n1) Help\n2) Browse\n3) Recommendation\n4) Share\n5) Reviews and Ratings\n6) Playlist\n7) Logout\n\nEnter number: ");
                        scanf("%d",&ans);
                        printf ("----------------------------------------------------------------------");
                        if (ans==1)
                        {
                            printf("\nYou have chosen the help option\n");
                            printf("\nHELP US IN IMPROVING OUR WEBSITE\n");
                            help(unum);
                            logout=2;
                        }
                        else if (ans==2)
                        {
                            printf("\nYou have chosen the browse option\n");
                            printf("\nLET'S SEARCH FOR SOME GREAT MOVIES\n");
                            logout=2;
                            browse(unum,movie,desc);
                        }
                        else if (ans==3)
                        {
                            printf("\nYou have chosen the recommendation option\n");
                            printf("\nWE WOULD LOVE TO GIVE YOU ONE OF OUR BEST RECOMMENDED MOVIE FROM OUR MOVIES LIST!\n");
                            logout=2;
                            recommend(unum, movie, desc, cine);
                        }
                        else if (ans==4)
                        {
                            printf("\nYou have chosen the share option\n");
                            printf("\nYOUR FRIEND WOULD LOVE THESE MOVIES!\n");
                            mshare (uugenre, movie, comedy, thriller, animation, action, scifi);
                            logout=2;
                        }
                        else if (ans==5)
                        {
                            printf("\nYou have chosen the option to give a review or rating\n");
                            printf("\nWANT TO RATE OR REVIEW ANY MOVIE! U HAVE COME TO THE RIGHT PLACE!\n");
                            ratingreview(unum,rating,review,movie);
                            logout=2;
                        }
                        else if (ans==6)
                        {
                            printf("\nYou have chosen the option to view your playlist\n");
                            printf("\nLETS SEE THE NUMBER OF MOVIES U HAVE IN YOUR PLAYLIST!\n");
                            playlist(unum, ugenre, uugenre, comedy, thriller, animation, action, scifi);
                            logout=2;
                        }
                        else if (ans==7)
                        {
                            printf("\nLEAVING ALREADY? HOPE U HADE A GREAT TIME!!");
                            printf("\nDo you wish to log out of your account? \n1) Enter 1 to log out\n2) Enter 2 to continue using the website using the same account.\nEnter number: ");
                            scanf("%d",&logout);
                        }
                        else
                        {
                            printf("\nYou havent pressed an invalid option. We will redirect you to the homepage");
                            logout=2;
                        }
                    } while (logout!=1);
                }   
                else 
                {
                    printf("\nThe password you entered is wrong");
                } 
            } 
        } while (found==0);
        printf("\nWould you like to login to another account?\n1) Press 1 to login again.\n2) If you wish to quit, press any other key\nEnter key: ");
        scanf("%d",&o);
    } while(o==1);
    if (o!=1)
    {
        exit(0);
    }
    return 0;
}

const char* account(int i, int acc[3], int age[3], char email[3][20], char pw[3][10], char name[3][20], char genre[5][15])
{
    acc[i]=i+1;
    printf ("\n----------------------------------------------------------------------");
    printf("\nYour acc number is %d.\nKindly note this number as it would be useful for logging into your account.\n\n", acc[i]);
    printf("Enter your name: ");
    scanf("%s",&name[i][20]);
    printf("Enter your age: ");
    scanf("%d",&age[i]);
    printf("Enter your email ID: ");
    scanf("%s",&email[i][20]);
    printf("Enter a valid password for your account: ");
    scanf("%s",&pw[i][10]);
    int num;
    char temp[50];
    char *ptr;
    ptr=temp;
    printf("\nEnter your favourite genre of movie:\nEnter 0 for genre COMEDY\nEnter 1 for genre THRILLER\nEnter 2 for genre ANIMATION\nEnter 3 for genre ACTION\nEnter 4 for genre SCIENCE FICTION\nEnter number: ");
    scanf("%d", &num);
    printf("Your favorite genre is: ");
    strcpy(temp,genre[num]);
    return ptr;
}

void movielist(int unum, char movie[17][50], char desc[17][1000], double cine[17],  char comedy[5][50], char thriller[3][50], char animation[3][50], char action[3][50], char scifi[3][50])
{
    cine[1]=3.6;
    cine[2]=3.2;
    cine[3]=3.1;
    cine[4]=4.1;
    cine[5]=3.2;
    cine[6]=4.3;
    cine[7]=4.0;
    cine[8]=4.4;
    cine[9]=4.7;
    cine[10]=4.7;
    cine[11]=4.2;
    cine[12]=4.4;
    cine[13]=4.6;
    cine[14]=2.5;
    cine[15]=3.15;
    cine[16]=4.375;
    cine[17]=3.95;
    strcpy(movie[1],"Home Alone");
    strcpy(movie[2],"Mr. Bean's Holiday");
    strcpy(movie[3],"Baby's Day Out");
    strcpy(movie[4],"Monty Python's Holy Grail");
    strcpy(movie[5],"The Dictator");
    strcpy(movie[6],"Inferno");
    strcpy(movie[7],"The Da Vinci Code");
    strcpy(movie[8],"Angels and Demons");
    strcpy(movie[9],"Coco");
    strcpy(movie[10],"The Lion King");
    strcpy(movie[11],"Spider-man-Into the Spider-verse");
    strcpy(movie[12],"Rush Hour");
    strcpy(movie[13],"Mission Impossible");
    strcpy(movie[14],"The Spy Next Door");
    strcpy(movie[15],"Arrival");
    strcpy(movie[16],"Inception");
    strcpy(movie[17],"Interstellar");
    strcpy(desc[1],"\n\nDIRECTOR: Chris Columbus\nWRITTEN BY: John Hughes\n\nPLOT: An eight-year-old troublemaker must protect his house from a pair of burglars when he is accidentally left home alone by his family during Christmas vacation.\n\nCAST: Macaulay Culkin as Kevin, Joe Pesci as Harry\nDURATION:1h 43m\nRELEASE DATE: 18 October 1991\nWARNINGS: Children aged above 10 years, violence, coarse language and some sexual references.\nBOX OFFICE\nVALUE: 47.67 crores USD\nTRAILOR LINK: YouTube - https://youtu.be/jEDaVHmw7r4 \nSTREAMING WEBSITE: Watch Home Alone on Disney+\nCENIPAL RATING: 3.6/5");
    strcpy(desc[2],"\n\nDIRECTOR: Steve Bendelack\nWRITTEN BY: Rowan Atkinson(character), Richard Curtis(character), Simon McBurney(story)\n\nPLOT SUMMARY: Mr. Bean wins a trip to Cannes where he unwittingly separates a young boy from his father and must help the two reunite. On the way he discovers France, bicycling, and true love.\n\nCAST DETAILS: Rowan Atkinson, Willem Dafoe\nDURATION: 1h 30m\nRELEASE DATE: 2007\nWARNING: aged six and over, trigger warning (suicide)\nBOX OFFICE VALUE: 23.22 crores USD\nTRAILER LINK: YouTube - https://youtu.be/hSxLUd8aly4 \nSTREAMING WEBSITE: Netflix\nMoviesharer RATING: 3.2/5");
    strcpy(desc[3],"\n\nDIRECTOR: Patrick Read Johnson\nWRITTEN BY: John Hughes\n\nPLOT SUMMARY: After three kidnappers lose the baby they have kidnapped, both the cops and kidnappers go looking for the baby. They have a harder time keeping hold of the baby. \n\nCAST DETAILS: Lara Flynn Boyle, Joe Mantegna\nDURATION: 1h 39m\nRELEASE DATE: 1994\nWARNING: VIOLENCE, trigger warning (kidnapping)\nBOX OFFICE VALUE: 3 crores USD\nTRAILER LINK: YouTube - https://youtu.be/u536l4ovhkw \nSTREAMING WEBSITE: Disney+ Hotstar\nMoviesharer RATING: 3.1/5");
    strcpy(desc[4],"\n\nDIRECTOR: Terry Gilliam, Terry Jones\nWRITTEN BY: Graham Chapman, John Cleese, Eric Idle\n\nPLOT SUMMARY: King Arthur and his Knights of the Round Table embark on a surreal, low-budget search for the Holy Grail, encountering many, very silly obstacles.\n\nCAST DETAILS: Graham Chapman, John Cleese\nDURATION: 1h 31m \nRELEASE DATE: 1975\nWARNING: 13 years above, sexual content and violence\nBOX OFFICE VALUE: 50 lakhs USD\nTRAILER LINK: Youtube - https://youtu.be/urRkGvhXc8w \nSTREAMING WEBSITE: Netflix\nMoviesharer RATING: 4.1/5");
    strcpy(desc[5],"\n\nDIRECTOR: Larry Charles\nWRITTEN BY Sacha Baron Cohen\n\nPLOT SUMMARY: The heroic story of a dictator who risked his life to ensure that democracy would never come to the country he so lovingly oppressed.\n\nCAST DETAILS: Sacha Baron Cohen, Anna Faris\nDURATION: 1h 23m\nRELEASE DATE: 2012\nWARNING: 17+, Graphic language, graphic violence, graphic nudity, sexual content and themes (including rape and child abuse) and graphic bodily functioning.\nBOX OFFICE VALUE: 17.94 crores USD\nTRAILER LINK: YouTube - https://youtu.be/cYplvwBvGA4 \nSTREAMING WEBSITE: Amazon Prime\nMoviesharer RATING: 3.2/5");
    strcpy(desc[6],"\n\nDIRECTOR: Ron Howard\nWRITTEN BY: Dan Brown \nGENRE: Thriller\n\nPLOT SUMMARY:  After waking up with amnesia in a hospital, Robert Langdon teams up with Sienna Brooks, one of his doctors, to protect the world from the evil plan of a mad scientist.\n\nCAST DETAILS: Tom Hanks, Felicity Jones\nDURATION: 2h 1m\nRELEASE DATE: October 28, 2016\nWARNING: U/A\nBOX OFFICE VALUE: $220 million USD\nTRAILER LINK: YouTube - https://youtu.be/RH2BD49sEZI \nSTREAMING WEBSITE: SonyLiv\nMoviesharer RATING: 4.3/5");
    strcpy(desc[7],"\n\nDIRECTOR: Ron Howard\nWRITTEN BY: Dan Brown\nGENRE: Thriller\n\nPLOT SUMMARY: Symbologist Robert Langdon travels from Paris to London to unravel a bizarre murder. Accompanied by a cryptographer, he soon comes across a religious enigma protected by an age-old secret society.\n\nCAST DETAILS: Tom Hanks, Audrey Tautou\nDURATION: 2h 29m\nRELEASE DATE: 19 May 2006\nWARNING: U/A\nBOX OFFICE VALUE: $760 million USD\nTRAILER LINK: YouTube - https://youtu.be/5sU9MT8829k \nSTREAMING WEBSITE: Netflix\nMoviesharer RATING: 4/5");
    strcpy(desc[8],"\n\nDIRECTOR: Ron Howard\nWRITTEN BY: Dan Brown\nGENRE: Thriller\n\nPLOT SUMMARY: Robert, a symbologist, tries his best to stop a secret society from destroying Vatican City. He seeks to decipher various clues in the process, most of which lead him to the four altars of science.\n\nCAST DETAILS: Tom Hanks (Actor), Ayelet Zuler(Actress)\nDURATION: 2h 18m\nRELEASE DATE: 29 May 2009\nWARNING: U/A\nBOX OFFICE VALUE: $485.9 million USD\nTRAILER LINK: YouTube - https://youtu.be/GPaAwbveFLg \nSTREAMING WEBSITE: Netflix\nMoviesharer RATING: 4.4/5");
    strcpy(desc[9],"\n\nDIRECTOR: Adrian Molina\nWRITTEN BY: Lee Unkrich\n\nPLOT SUMMARY: Miguel pursues his love for singing in spite of his family's ban on music. He stumbles into the Land of the Dead, where he learns about his great-great-grandfather who was a legendary singer\n\nCAST DETAILS: Anthony Gonzalez, Benjamin Bratt\nDURATION: 1h 45m\nRELEASE DATE: 22 November 2017\nWARNING: U\nBOX OFFICE VALUE: $807.8 million\nTRAILER LINK: YouTube - https://youtu.be/Ga6RYejo6Hk \nSTREAMING WEBSITE: Disney+Hotstar\nMoviesharer RATING: 4.7/5");
    strcpy(desc[10],"\n\nDIRECTOR: Roger Allers\nWRITTEN BY: Irene Mecchi\n\nPLOT SUMMARY: Lion prince Simba and his father are targeted by his bitter uncle, who wants to ascend the throne himself.\n\nCAST DETAILS: Rowan Atkinson, James Earl Jones\nDURATION: 1h 28m\nRELEASE DATE: 24 June 1994\nWARNING: U\nBOX OFFICE VALUE: $968.5 million\nTRAILER LINK: YouTube - https://youtu.be/7TavVZMewpY \nSTREAMING WEBSITE: Disney+Hotstar\nMoviesharer RATING: 4.7/5");
    strcpy(desc[11],"\n\nDIRECTOR: Peter Ramsey\nWRITTEN BY: Phil Lord\n\nPLOT SUMMARY: After gaining superpowers from a spider bite, Miles Morales protects the city as Spider-Man. Soon, he meets alternate versions of himself and gets embroiled in an epic battle to save the multiverse.\n\nCAST DETAILS: Hailee Steinfeld, Shameik Moore\nDURATION: 1h 56m\nRELEASE DATE: 14 December 2018\nWARNING: U\nBOX OFFICE VALUE: $375.5 million\nTRAILER LINK: YouTube - https://youtu.be/g4Hbz2jLxvQ \nSTREAMING WEBSITE: YouTube\nMoviesharer RATING: 4.2/5");
    strcpy(desc[12],"\n\nDIRECTOR: Brett Ratner\nWRITTEN BY: Ross LaManna\n\nPLOT SUMMARY: When a Chinese diplomat's daughter is kidnapped in Los Angeles, he calls in Hong Kong Detective Inspector Lee (Jackie Chan) to assist the FBI with the case. But the FBI doesn't want anything to do with Lee, and they dump him off on the LAPD, who assign wisecracking Detective James Carter (Chris Tucker) to watch over him. Although Lee and Carter can't stand each other, they choose to work together to solve the case on their own when they figure out they've been ditched by both the FBI and police.\n\nCAST DETAILS: Jackie Chan, Chris Tucker, Ken\nDURATION: 1h 38 mins\nRELEASE DATE:18 September1998\nWARNING: Its a PG 13 movie\nBOX OFFICE VALUE: $244.4 million USD\nTRAILER LINK: You Tube - https://youtu.be/JMiFsFQcFLE \nSTREAMING WEBSITE: Netflix\nMoviesharer RATING: 4.4/5");
    strcpy(desc[13],"\n\nDIRECTOR: Brian De Palma\nWRITTEN BY: David Koepp\n\nPLOT SUMMARY: When U.S. government operative Ethan Hunt (Tom Cruise) and his mentor, Jim Phelps (Jon Voight), go on a covert assignment that takes a disastrous turn, Jim is killed, and Ethan becomes the prime murder suspect. Now a fugitive, Hunt recruits brilliant hacker Luther Stickell (Ving Rhames) and maverick pilot Franz Krieger (Jean Reno) to help him sneak into a heavily guarded CIA building to retrieve a confidential computer file that will prove his innocence.\n\nCAST DETAILS: Tom Cruise, Jon Voight ,Henry Czerny\nDURATION: 1h 50 mins\nRELEASE DATE: 22 May 1996\nWARNING: Its a PG 13 movie\nBOX OFFICE VALUE: $80 million USD\nTRAILER LINK: YouTube - https://youtu.be/Ohws8y572KE \nSTREAMING WEBSITE: Netflix\nMoviesharer RATING: 4.6/5");
    strcpy(desc[14],"\n\nDIRECTOR: Brian Levant\nWRITTEN BY: Gregory Poirier\n\nPLOT SUMMARY: Bob Ho (Jackie Chan), an undercover operative for the CIA, decides to give up his career and marry his girlfriend, Gillian (Amber Valletta). First however, he has one more mission to complete: Gain the approval of Gillian's children. Bob volunteers to baby-sit when Gillian is called away, but the operation hits a snag when one of the kids mistakenly downloads a top-secret formula, and a Russian terrorist takes aim at Bob's prospective family.\n\nCAST DETAILS: Jackie Chan, Amber Valletta , Madeline Carroll\nDURATION: 1h 34mins\nRELEASE DATE: 15 January 2010\nWARNING: The Spy Next Door is rated PG by the MPAA for sequences of action violence and some mild rude humor.\nBOX OFFICE VALUE: $45.2 million USD\nTRAILER LINK: YouTube - https://youtu.be/fa2RZf0m39g \nSTREAMING WEBSITE: Amazon Prime\nMoviesharer RATING: 2.5/5");
    strcpy(desc[15],"\n\nDIRECTOR: Denis Villeneuve\nWRITTEN BY: Eric Heisserer and Ted Chiang\n\nPLOT SUMMARY: A linguist works with the military to communicate with alien lifeforms after twelve mysterious spacecraft appear around the world.\n\nCAST DETAILS: Amy Adams, Jeremy Renner, Forest Whitaker, Michael Stuhlbarg\nDURATION: 1h 56mins\nRELEASE DATE: January 31, 2017\nWARNING: It is rated as PG-13\nBOX OFFICE VALUE: 47 million USD\nTRAILER LINK: YouTube - https://youtu.be/tFMo3UJ4B4g \nSTREAMING WEBSITE: Netflix\nMoviesharer RATING: 3.15/5");
    strcpy(desc[16],"\n\nDIRECTOR: Christopher Nolan\nWRITTEN BY: Christopher Nolan\n\nPLOT SUMMARY: A thief who steals corporate secrets through the use of dream-sharing technology is given the inverse task of planting an idea into the mind of a C.E.O., but his tragic past may doom the project and his team to disaster.\n\nCAST DETAILS: Leonardo DiCaprio, Joseph Gordon-Levitt and Elliot Page\nDURATION: 2h 28mins\nRELEASE DATE: 16 July 2010\nWARNING: The MPAA rated Inception PG-13 for sequences of violence and action throughout.\nBOX OFFICE VALUE: 836.8 million USD\nTRAILER LINK: YouTube - \nSTREAMING WEBSITE: Netflix\nMoviesharer RATING: 4.375");
    strcpy(desc[17],"\n\nDIRECTOR: Christopher Nolan\nWRITTEN BY: Christopher Nolan and Jonathan Nolan\n\nPLOT SUMMARY: A team of explorers travel through a wormhole in space in an attempt to ensure humanity's survival\n\nCAST DETAILS: Matthew McConaughey, Anne Hathaway and Jessica Chastain\nDURATION: 2h 49mins\nRELEASE DATE: 7 November 2014\nWARNING: Interstellar is rated PG-13 by the MPAA for some intense perilous action and brief strong language. Violence: Characters are frequently in peril and some die.\nBOX OFFICE VALUE: 701.8 million USD\nTRAILER LINK: YouTube - https://youtu.be/zSWdZVtXT7E \nSTREAMING WEBSITE: Amazon Prime\nMoviesharer RATING: 3.95/5");
    int i;
    for (i=0; i<5; i++)
    {
        strcpy(comedy[i],movie[i+1]);  
    }
    for (i=0; i<3; i++)
    {
        strcpy(thriller[i],movie[i+6]);
    }
    for (i=0; i<3; i++)
    {
        strcpy(animation[i],movie[i+9]);
    }
    for (i=0; i<3; i++)
    {
        strcpy(action[i],movie[i+12]);
    }
    for (i=0; i<3; i++)
    {
        strcpy(scifi[i],movie[i+15]);
    }
}

void help(int unum)
{
    int ans2, ans3;
    printf("\nYou have two options to choose from:\n1) Help in navigating our website\n2) Help us by navigating our website to the right path by giving us some suggestions\nEnter number: ");
    scanf("%d",&ans2);
    if (ans2==1)
    {
        printf("\nYou have two options to choose from:\n1) Contact the Developers\n2) Download PDF containing repeatedly asked questions and solutions\nEnter number: ");
        scanf("%d",&ans3);
        if (ans3==1)
        {
            printf("\nDevelopers' Phone number: 1111122222\nDevelopers' Email ID: Moviesharer@gmail.com");
            printf("\nOur customer services are always at your disposal!\nIf we couldnt answer your inquiry presently , we will get right back to you!");
        }
        else
        {
            printf("\nVisit this site to download PDF with steps for solving any issue with the website: www.downloadpdf.com");
        }
    }
    else
    {
        char suggestion[3][1000],complaint[3][1000];
        printf("\nYou have two options to choose from:\n1) Suggestions to help improve our website\n2) Complaint Box\nEnter number: ");
        scanf("%d",&ans3);
        if (ans3==1)
        {
            printf("\nEnter your suggestion: ");
            scanf(" %[^\n]", suggestion[unum]);
            printf("\nThank you for helping us improve our website!\nOur Developers will get right to it and work towards making the website better for you, our valuable customers!");
        }
        else
        {
            printf("\nEnter your complaint: ");
            scanf(" %[^\n]", complaint[unum]);
            printf("\nWe sincerly apologize for the inconvinience caused.\nOur developers will get right to fixing it! Thank you for your feedback!");
        }
    }
}

void browse(int unum, char movie[17][50], char desc[17][1000])
{
    int gen, jj, w;
    do
    {
        printf("\nPlease choose the genre in which you wish to watch a movie in:\nEnter 1 for Comedy\nEnter 2 for Thriller\nEnter 3 for Animation\nEnter 4 for Action\nEnter 5 for Science Fiction\nEnter number: ");
        scanf("%d",&gen);
        printf("\nFANTASTIC CHOICE!");
        if (gen==1)
        {
            for(w=0;w<=4;w++)
            {
                printf("\n\n%s",&movie[w][50]);
                printf("%s",&desc[w][1000]);
            }
            jj=2;
        }
        else if (gen==2)
        {
            for(w=5;w<=7;w++)
            {
                printf("\n\n%s",&movie[w][50]);
                printf("%s",&desc[w][1000]);
            }
            jj=2;
        }
        else if (gen==3)
        {
            for(w=8;w<=10;w++)
            {
                printf("\n\n%s",&movie[w][50]);
                printf("%s",&desc[w][1000]);
            }
            jj=2;
        }
        else if (gen==4)
        {
            for(w=11;w<=13;w++)
            {
                printf("\n\n%s",&movie[w][50]);
                printf("%s",&desc[w][1000]);
            }
            jj=2;
        }
        else if (gen==5)
        {
            for(w=14;w<=16;w++)
            {
                printf("\n\n%s",&movie[w][50]);
                printf("%s",&desc[w][1000]);
            }
            jj=2;
        }
        else
        {
            printf("\nOops! looks like you have entered a wrong genre option. Enter a valid genre option.");
            jj=1;
        }
    } while (jj==1);
}

void recommend(int unum,char movie[17][50],char desc[17][1000], double cine[17])
{
    int recom, recoms, inp;
    do
    {
        printf("\nWould you like Moviesharer to recommend a movie for you?\nEnter 1 for receiving a random movie recommendation.\nEnter 2 for receiving movie recommendations based on their Moviesharer rating\nEnter number: ");
        scanf("%d",&recom);
        srand(time(0));
        if (recom==1)
        {
            recoms=rand()%17;
            printf("\nYour recommended movie is %s",&movie[recoms][50]);
            printf("\nHOPE YOU LIKE IT!");
            printf("%s",&desc[recoms][1000]);
            inp=2;
        }
        else if (recom==2)
        {
            inp=2;
            sort();
        }
        else
        {
            printf("\nYou have entered an invalid input");
            inp=1;
        }
    } while (inp==1);
}

struct Sort { 
    char* name; 
    int id; 
    float ratings; 
}; 

void sort()
{
    struct Sort arr[20] ,temp;
    int i , j,n; 
    printf("Enter number of movies: ");
    scanf("%d",&n);
    
    arr[0].id = 1; 
    arr[0].name = "Home Alone"; 
    arr[0].ratings = 3.6; 
    
    arr[1].id = 2;
    arr[1].name = "Mr. Bean's Holiday"; 
    arr[1].ratings = 3.2; 
    
    arr[2].id = 3; 
    arr[2].name = "Baby's Day Out"; 
    arr[2].ratings = 3.1; 
    
    arr[3].id = 4; 
    arr[3].name = "Monty Python's Holy Grail"; 
    arr[3].ratings = 4.1; 
    
    arr[4].id = 5; 
    arr[4].name = "The Dictator"; 
    arr[4].ratings = 3.2; 
    
    arr[5].id = 6; 
    arr[5].name = "Inferno"; 
    arr[5].ratings = 4.3; 
    
    arr[6].id = 7; 
    arr[6].name = "The Da Vinci Code"; 
    arr[6].ratings = 4.0; 
    
    arr[7].id = 8; 
    arr[7].name = "Angels and Demons"; 
    arr[7].ratings = 4.4; 
    
    arr[8].id = 9; 
    arr[8].name = "Coco"; 
    arr[8].ratings = 4.7; 
    
    arr[9].id = 10; 
    arr[9].name = "The Lion King"; 
    arr[9].ratings = 4.7; 
    
    arr[10].id = 11; 
    arr[10].name = "Spider-man-Into the Spider-verse"; 
    arr[10].ratings = 4.2; 
    
    arr[11].id = 12; 
    arr[11].name = "Rush Hour"; 
    arr[11].ratings = 4.4; 
    
    arr[12].id = 13; 
    arr[12].name = "Mission Impossible"; 
    arr[12].ratings = 4.6; 
    
    arr[13].id = 14; 
    arr[13].name = "The Spy Next Door"; 
    arr[13].ratings = 2.5; 
    
    arr[14].id = 15; 
    arr[14].name = "Arrival"; 
    arr[14].ratings = 3.15; 
    
    arr[15].id = 16; 
    arr[15].name = "Inception"; 
    arr[15].ratings = 4.375; 
    
    arr[16].id = 17; 
    arr[16].name = "Interstellar"; 
    arr[16].ratings = 3.95; 
    for(i=0;i< 17-1;i++)
    {
        for(j=i+1;j< 17;j++)
        {
            if(arr[i].ratings<arr[j].ratings)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("\nMovie names recommended by ratings:\n"); 
    for(i=0;i< n;i++)
    { 
        printf("Name = %s, Ratings = %0.1f \n", arr[i].name, arr[i].ratings);
    } 
}


void mshare (char uugenre[3][50], char movie[17][50], char comedy[5][50], char thriller[3][50], char animation[3][50], char action[3][50], char scifi[3][50])
{
    int svar, sm, smovie, sssvar, n;
    do
    {
         do
        {
            printf("HELP YOUR FRIENDS IN FINDING THE BEST MOVIES!");
            printf("\nEnter your favourite genre of movie:\nEnter 0 for genre COMEDY\nEnter 1 for genre THRILLER\nEnter 2 for genre ANIMATION\nEnter 3 for genre ACTION\nEnter 4 for genre SCIENCE FICTION\nEnter number: ");
            scanf("%d", &svar);
            sm=1;
            if (svar==0)
            {
                printf("\nHOPE YOUR FRIEND LIKES HUMOROUS MOVIES");
                printf("\nYou have chosen to share a movie from the genre COMEDY. \nKindly choose which movies you want to share from this genre.");
                for (int i=0; i<=4;i++)
                {
                    printf("\nEnter %d for sharing %s ",i,comedy[i]);
                }
                printf("\nEnter number: ");
                scanf("%d",&smovie);
                if (smovie>4)
                {
                    printf("\nThere exists no movie with the movie number you have entered under this genre. \nKindly enter a valid movie number to pick your option.");
                    sm=0;
                }
            }
            else if (svar==1)
            {
                printf("\nHOPE YOUR FRIEND LIKES A MOVIE THAT KEEPS YOU HANGING TILL THE END");
                printf("\nYou have chosen to share a movie from the genre THRILLER. \nKindly choose which movies you want to share from this genre.");
                for (int j=0; j<=2;j++)
                {
                    printf("\nEnter %d for sharing %s", j+5, thriller[j]);
                }
                printf("\nEnter number: ");
                scanf("%d",&smovie);
                if (smovie<5 || smovie>7)
                {
                    printf("\nThere exists no movie with the movie number you have entered under this genre. \nKindly enter a valid movie number to pick your option.");
                    sm=0;
                }
            }
            else if (svar==2)
            {
                printf("\nOHH ANIMATION!,YOUR FRIEND WOULD LOVE THESE MOVIES");
                printf("\nYou have chosen to share a movie from the genre ANIMATION. \nKindly choose which movies you want to share from this genre.");
                for (int k=0; k<=2;k++)
                {
                    printf("\nEnter %d for sharing %s", k+8, animation[k]);
                }
                printf("\nEnter number: ");
                scanf("%d",&smovie);
                if (smovie<8 || smovie>10)
                {
                    printf("\nThere exists no movie with the movie number you have entered under this genre. \nKindly enter a valid movie number to pick your option.");
                    sm=0;
                }
            }
            else if (svar==3)
            {
                printf("\nWHO DOESN'T LIKE ACTION MOVIES!");
                printf("\nYou have chosen to share a movie from the genre ACTION. \nKindly choose which movies you want to share from this genre.");
                for (int l=0; l<=2;l++)
                {
                    printf("\nEnter %d for sharing %s", l+11, action[l]);
                }
                printf("\nEnter number: ");
                scanf("%d",&smovie);
                if (smovie<11 || smovie>13)
                {
                    printf("\nThere exists no movie with the movie number you have entered under this genre. \nKindly enter a valid movie number to pick your option.");
                    sm=0;
                }
            }
            else if (svar==4)
            {
                printf("\nWHO SAID SCI-FI is boring!");
                printf("\nYou have chosen to share a movie from the genre SCI-FI. \nKindly choose which movies you want to share from this genre.");
                for (int m=0; m<=2;m++)
                {
                    printf("\nEnter %d for sharing %s", m+14, scifi[m]);
                }
                printf("\nEnter number: ");
                scanf("%d",&smovie);
                if (smovie<14 || smovie>16)
                {
                    printf("\nThere exists no movie with the movie number you have entered under this genre. \nKindly enter a valid movie number to pick your option.");
                    sm=0;
                }
            }
            else
            {
                printf("\nWrong option");
                sm=0;
            }
        }while(sm==0);
        printf("\nEnter the user number of your friend to whom you wish to share the movie you have selected: ");
        scanf("%d", &sssvar);
        sssvar=sssvar-1;
        uugenre[sssvar]==uugenre[sssvar]&&movie[smovie];  
        printf("\nYour movie has been successfully shared!");
        printf("\nEnter 1 to share another movie. Otherwise click any other key.\nEnter key: ");
        scanf("%d", &n);
    }while(n==1);
}

void ratingreview(int unum,double rating[17],char review[17][1000],char movie[17][50])
{
    int ans4,mnum;
    double ratings;
    char reviews[1000];
    printf("\nEnter your required option\n1 Review\n2 Rating\nEnter number: ");
    scanf("%d",&ans4);
    printf("\nEnter the movie number: ");
    scanf("%d",&mnum);
    printf("\nThe movie for which you wish to enter a recommendation is : %s",&movie[mnum][50]);
    if (ans4==1)
    {
        printf("\nEnter the review for the movie: ");
        scanf(" %[^\n]",reviews);
        review[mnum][1000]=reviews[1000];
    }
    else
    {
        printf("\nEnter the rating out of 5 stars (5 being the best rating for a movie): ");
        scanf("%lf",&ratings);
        rating[mnum]=ratings;
    }
}

void playlist(int unum, char ugenre[3][50], char uugenre[3][50], char comedy[5][50], char thriller[3][50], char animation[3][50], char action[3][50], char scifi[3][50])
{
    int i, j, num;
    num=unum-1;
    printf("\nHere is the recommended playlist based on the genre you preferred while creating your account: %s", ugenre[num]);
    if ((strcmp(ugenre[num],"COMEDY"))==0)
    {
        printf("\nHAVE YOU EVER LAUGHED AT THE ONCE WHO DO NOT GET THE JOKE!");
        for (i=0;i<4;i++)
        {
            printf("\n%s", &comedy[i][50]);
        }
    }
    else if ((strcmp(ugenre[num],"THRILLER"))==0)
    {
        printf("\nI LOVE THE HORROR GENRE AND THE THRILLER GENRE, SO I'VE GOT NO PROBLRM WITH PLAYING A PSYCHO");
        for (i=0;i<2;i++)
        {
            printf("\n%s", &thriller[i][50]);
        }
    }
    else if ((strcmp(ugenre[num],"ANIMATION"))==0)
    {
        printf("\nI'M NOT BAD AND THAT'S GOOD.I WILL NEVER BE GOOD AND THAT'S NOT BAD. REMEMBER THIS QUOTE!");
        for (i=0;i<2;i++)
        {
            printf("\n%s", &animation[i][50]);
        }
    }
    else if ((strcmp(ugenre[num],"ACTION"))==0)
    {
        printf("\nI GUESS HOLLYWOOD WANTS TO SEE ME DO ACTION. SO I AM DOWN");
        for (i=0;i<2;i++)
        {
            printf("\n%s", &action[i][50]);
        }
    }
    else if ((strcmp(ugenre[num],"SCIENCEFICTION"))==0)
    {
        printf("\nALIENS, HERE WE COME! A.I, SPACE EXLORATION AND OTHER COOL STUFFS TO EXPERIENCE");
        for (i=0;i<2;i++)
        {
            printf("\n%s", &scifi[i][50]);
        }
    }
    if ((strcmp(ugenre[num],""))==0);
    printf("\nINCOMING MOVIES!!!");
}

