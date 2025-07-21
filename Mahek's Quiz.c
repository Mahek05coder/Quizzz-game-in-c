#include <stdio.h>
#include<time.h>

int main() {
    // Questions
    char questions[][100] = {
        "What is the capital of India?",
        "Who is the father of C language?",
        "Which data type is used to store characters?",
        "what is the national sport in India?",
        "which team won the nations league final?",
        "Who is the Caption of Portugal team?",

    };

    // Options for each question
    char options[][4][50] = {
        {"Mumbai", "Delhi", "Kolkata", "Chennai"},
        {"Dennis Ritchie", "Bjarne Stroustrup", "James Gosling", "Steve Jobs"},
        {"int", "float", "char", "double"},
        {"Football", "Cricket", "Hockey", "Kho-Kho"},
        {"France","Portugal","Germany","Argentina"},
        {"Vitinha","Nuno","Ronaldo","Matheus"},
    };

    // Correct answers (index +1)
    int correctAnswers[] = {2, 1, 3, 2,2,3};  // 1-based index (Delhi, Dennis, char)

    int userAnswer;
    int score = 0;
    time_t start,end;
    double timeTaken;

    printf("Welcome to Mahek's Quiz Game!\n\n");
    printf("You have 10 seconds to answer each Questions.\n\n");

    for (int i=0; i<6; i++) {
        printf("Q%d: %s\n", i+1, questions[i]);

        for (int j = 0; j <4 ; j++) {
            printf("%d. %s\n", j+1, options[i][j]);
        }

        printf("Your answer (1-4): ");
        time(&start);
        scanf("%d", &userAnswer);

        time(&end);
        timeTaken=difftime(end,start);

        if(timeTaken>10.0)
        {
            printf("Time's up! you took %.0f seconds.");
            continue;
        }

        if (userAnswer == correctAnswers[i]) {
            printf("Correct! (Answered in %.0f seconds\n\n");
            score++;
        } else {
            printf(" Wrong! Correct answer is: %s\n\n", options[i][correctAnswers[i] - 1]);
        }
    }

    printf("Quiz Over! You scored: %d/6\n", score);

    if (score==6)
    {
        printf("Excellent! You're a genius!\n");
    }
    else if(score>=4)
    {
        printf("Good job! keep practicing.\n");
    }
    else{
        printf("Keep learning.You'll do better next time\n");
    }

    return 0;
}
