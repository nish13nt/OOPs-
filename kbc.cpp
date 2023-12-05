// KBC Game by Yash & Nishant
// OOP Mini Project

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

bool flag = 1, fifty_flag = 1, two_flag = 1, ask_flag = 1, phone_flag = 1;
int llans;

class Question
{
public:
    string query;
    string option1;
    string option2;
    string option3;
    string option4;
    int correctAns;

    Question(string q, string op1, string op2, string op3, string op4, int ans)
    {
        query = q;
        option1 = op1;
        option2 = op2;
        option3 = op3;
        option4 = op4;
        correctAns = ans;
    }

    void displayQuestion()
    {
        cout << query << endl;
        cout << "1. " << option1 << string(30 - option1.length(), ' ') << "3. " << option3 << endl;
        cout << "2. " << option2 << string(30 - option2.length(), ' ') << "4. " << option4 << endl;
    }
};

class Game
{
public:
    vector<Question> questions;
    vector<int> price = {1000, 2000, 3000, 5000, 10000, 20000, 40000, 80000, 160000, 320000, 640000, 1250000, 2500000, 5000000, 10000000, 70000000};
    int i;

    Game()
    {
        questions.push_back(Question("The International Literacy Day is observed on ", "Sep 8", "Nov 28", "May 2", "Sep 22", 1));

        questions.push_back(Question("The language of Lakshadweep. a Union Territory of India, is ", "Hindi", "Marathi", "Malayalam", "Telugu", 3));

        questions.push_back(Question("Which day is observed as the World Standards Day? ", "Jun 8", "Aug 2", "Oct 14", "Nov 15", 3));

        questions.push_back(Question("Bahubali festival is related to ", "Hinduism", "Islam", "Buddhism", "Jainism", 4));

        questions.push_back(Question("Who is the author of the epic 'Meghdoot? ", "Vishakadatta", "Valmiki", "Banabhatta", "Kalidas", 4));

        questions.push_back(Question("Van Mahotsav was started by ", "Maharshi Karve", "Bal Gangadhar Tilak", "K.M. Munshi", "Sanjay Gandhi", 3));

        questions.push_back(Question("The Krithi system was perfected and Carnatic music was given by ", "Arunagirinathan", "Purandaradasa", "Shyama Shastri", "Swati Tirunal", 4));

        questions.push_back(Question("Writers Building is the headquarters of ", "The time of India Group", "All India Writers Association", "West Bengal Government", "Press trust of India", 4));

        questions.push_back(Question("The Komark Temple is dedicated to ", "Vishnu", "Shiva", "Krishna", "Sun-God", 4));

        questions.push_back(Question("The 227 year old 'Nawab Saheb Ki Haveli' is Iocated at ", "Hyderabad", "Jaipur", "New Delhi", "Agra", 2));

        questions.push_back(Question("Which of the following Academy is responsible for fostering the development of dance, drama and music in India? ", "Lalit Kala Academy", "Sahitya Academy", "National School of Drama", "Sangeet Academy", 4));

        questions.push_back(Question("In which of the following countries has India not organised 'India Festival' ? ", "Russia", "Japan", "France", "West Germany", 4));

        questions.push_back(Question("The Indian National Calendar is based on ", "Christian era", "Saka era", "Vikram era", "Hiji era", 2));

        questions.push_back(Question("The abbreviation 'fob' stands for ", "Free on Board", "Free of Bargain", "Fellow of Britain", "None of these", 1));

        questions.push_back(Question("Which British Army unit was given the motto 'Primus in Indis' because it was the first to serve in India? ", "41st (Welsh) Regiment of Foot", "1st Coldstream Guards", "5th Light Infantry", "39th Regiment of Foot", 4));

        questions.push_back(Question("Who was the Indian bowler off whom Austrilian legend Don Bradman got a single to reach his 100th first class century? ", "Baqa Jilani", "Commandur Rangachari", "Gogumal Kishenchand", "Kanwar Rai Singh", 3));
    }

    // 50-50 lifeline
    void fifty_fifty(int ques_no) 
    {
        int correct = questions[ques_no].correctAns;
        int wrong1, wrong2;

        do
        {
            srand(time(0));
            wrong1 = rand() % 4 + 1;
        } while (wrong1 == correct);

        do
        {
            srand(time(0));
            wrong2 = rand() % 4 + 1;
        } while (wrong2 == wrong1 || wrong2 == correct);

        cout << "50-50 LifeLine : Options " << wrong1 << " and " << wrong2 << " are removed\n\n";
    }

    // ask audience lifeline
    void Ask_Audience()
    {
        cout << "Ask the Audience LifeLine: Audience suggests the answer is option " << questions[i].correctAns << endl
             << endl;
    }

    // Double Dip Lifeline
    int Two_Attempt(int ques_no)
    {
        int correct = questions[ques_no].correctAns;
        int attempt = 0, option;

        cout << "Two Attempt LifeLine : You have two attempts to answer\n\n";

        while (attempt <= 1)
        {
            cout << "Attempt " << attempt + 1 << endl;
            cout << "Enter your Option : ";
            cin >> option;

            if (option == correct)
            {
                cout << "Correct Answer\n";
                return option;
            }
            else
            {
                cout << "Wrong Answer\n";
                attempt++;
            }
        }
        cout << "Your both the attempts were wrong\n\n";
        return 0;
    }

    // Call a friend
    void Call_A_Friend()
    {
        cout << "ABC : +91 12345 67890\n";
        cout << "XYZ : +91 09876 54321\n";
        srand(time(0));
        int suggest = rand() % 5;
        if(suggest)
            cout<<"Your Friend suggest option number "<< suggest<<endl;
        else
            cout<<"Your Friend does not know the answer !!!\n";
    }


    void lifeline()
    {
        int option;
        if (fifty_flag)
        {
            cout << "1] 50-50 LifeLine\n";
        }
        if (ask_flag)
        {
            cout << "2] Ask Audience LifeLine\n";
        }
        if (two_flag)
        {
            cout << "3] Two Attempt LifeLine\n";
        }
        if (phone_flag)
        {
            cout << "4] Call A Friend\n";
        }
        if (fifty_flag || ask_flag || two_flag || phone_flag)
        {
            cout << "Enter your choice : ";
            cin >> option;
        }
        else
        {
            cout << "All LifeLines Exhausted\n\n";
            llans = -2;
        }

        if (option == 1 && fifty_flag)
        {
            fifty_fifty(i);
            fifty_flag = 0;
            cout << "Enter your Answer's Option Number [1 or 2 or 3 or 4] OR '-1' for LifeLine OR '0' to Quit: ";
            cin >> llans;
        }
        else if (option == 2 && ask_flag)
        {
            Ask_Audience();
            cout << "Enter your Answer's Option Number [1 or 2 or 3 or 4] OR '-1' for LifeLine OR '0' to Quit: ";
            cin >> llans;
            ask_flag = 0;
        }
        else if (option == 3 && two_flag)
        {
            llans = Two_Attempt(i);
            two_flag = 0;
        }
        else if (option == 4 && phone_flag)
        {
            Call_A_Friend();
            cout << "Enter your Answer's Option Number [1 or 2 or 3 or 4] OR '-1' for LifeLine OR '0' to Quit: ";
            cin >> llans;
            phone_flag = 0;
        }

        if (llans == -1 && (fifty_flag || two_flag || phone_flag || ask_flag))
        {
            lifeline();
        }
    }


    void playGame()
    {

        for (i = 0; i < 16; ++i)
        {
            cout << "Question for Rs. " << price[i] << endl;
            questions[i].displayQuestion();
            int ans;

        label: // used a goto statement 
            cout << "Enter your Answer's Option Number [1 or 2 or 3 or 4] OR '-1' for LifeLine OR '0' to Quit: ";
            cin >> ans;

            if (ans == 0)
            {
                break;
            }
            if (ans == -1)
            {
                lifeline();
            }
            // if statement for directly answered question
            if (ans == questions[i].correctAns && (ans == 1 || ans == 2 || ans == 3 || ans == 4))
            {
                cout << "\nCorrect Answer\n";
                if (i < 4)
                {
                    cout << "Won Rs. " << price[i] << endl
                         << endl;
                }
                else if (i >= 4 && i < 9)
                {
                    cout << "You have won Rs. " << price[i] << " and confirmed 10,000\n\n";
                }
                else if (i == 9)
                {
                    cout << "You have won Rs. " << price[i] << " and confirmed Rs. 3,20,000\nThe Jackpot Question of 7 Crore is Unlocked now\n\n";
                }
                else if (i == 10)
                {
                    cout << "You have won Rs. " << price[i] << "\n\n";
                }
                else if (i == 11)
                {
                    cout << "You have won Rs. " << price[i] << "\n\n";
                }
                else if (i == 12)
                {
                    cout << "You have won Rs. " << price[i] << "\n\n";
                }
                else if (i == 13)
                {
                    cout << "You have won Rs. " << price[i] << "\n\n";
                }

                else if (i == 14)
                {
                    cout << "You have won Rs. 1 Crore\nCongratulations!! Now you are CrorePati!!!\n\n";
                }
                else
                {
                    cout << "You have completed the game and won Rs. 7 Crore\n\n";
                }
            }
            // else if for any wrong answer
            else if (ans == 1 || ans == 2 || ans == 3 || ans == 4)
            {
                cout << "Wrong Answer\n";
                if (i > 9 && i < 16)
                {
                    cout << "Finally, You have won Rs. 3,20,000\n";
                    flag = 0;
                }
                break;
            }
            // else if statement for lifeline answered question
            else if (ans == -1)
            {
                if (llans == -1)
                {
                    lifeline();
                }
                if (llans == questions[i].correctAns)
                {
                    cout << "\nCorrect Answer\n";
                    if (i < 4)
                    {
                        cout << "Won Rs. " << price[i] << "\n\n";
                    }
                    else if (i >= 4 && i < 9)
                    {
                        cout << "You have won Rs. " << price[i] << " and confirmed 10,000\n\n";
                    }
                    else if (i == 9)
                    {
                        cout << "You have won Rs. " << price[i] << " and confirmed Rs. 3,20,000\nThe Jackpot Question of 7 Crore is Unlocked now\n\n";
                    }
                    else if (i == 10)
                    {
                        cout << "You have won Rs. " << price[i] << "\n\n";
                    }
                    else if (i == 11)
                    {
                        cout << "You have won Rs. " << price[i] << "\n\n";
                    }
                    else if (i == 12)
                    {
                        cout << "You have won Rs. " << price[i] << "\n\n";
                    }
                    else if (i == 13)
                    {
                        cout << "You have won Rs. " << price[i] << "\n\n";
                    }

                    else if (i == 14)
                    {
                        cout << "You have won Rs. 1 Crore\nCongratulations!! Now you are CrorePati!!!\n\n";
                    }
                    else
                    {
                        cout << "You have completed the game and won Rs. 7 Crore\n\n";
                    }
                }
                else if (llans == 0)
                {
                    break;
                }
                else if (llans == 1 || llans == 2 || llans == 3 || llans == 4)
                {
                    cout << "Wrong Answer\n";
                    if (i > 9 && i < 16)
                    {
                        cout << "Finally, You have won Rs. 3,20,000\n";
                        flag = 0;
                    }
                    break;
                }
                else
                {
                    goto label;
                }
            }
        }

        // Final Amount after exiting or wrong answer
        if (i >= 0 && i <= 4)
        {
            cout << "\nSorry You haven't won any prize money...:(" << endl;
        }
        else if (i >= 5 && i <= 9)
        {
            cout << "\nFinally, You have won Rs. 10,000\n";
        }
        else if (i == 10)
        {
            cout << "\nFinally, You have won Rs. 3,20,000\n";
        }
        else if (i == 11 && flag)
        {
            cout << "\nFinally, You have won Rs. 6,40,000\n";
        }
        else if (i == 12 && flag)
        {
            cout << "\nFinally, You have won Rs. 12,50,000\n";
        }
        else if (i == 13 && flag)
        {
            cout << "\nFinally, You have won Rs. 25,00,000\n";
        }
        else if (i == 14 && flag)
        {
            cout << "\nFinally, You have won Rs. 50,00,000\n";
        }
        else if (i == 15 && flag)
        {
            cout << "\nFinally, You have won Rs. 1 Crore\n";
        }
        else if (i == 16 && flag)
        {
            cout << "\nFinally, You have won Rs. 7 Crore\n";
        }
    }
};

int main()
{
    Game game;
    game.playGame();
    return 0;
}