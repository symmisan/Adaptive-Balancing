#include <iostream>
using namespace std;

// Calculates challenge score from 0 to 100
int calculateChallengeScore(int healthLost, int damageTaken, int accuracy,
                            int enemiesDefeated, int healingUsed) {
    int score = 50; // Start balanced

    // Add points for good performance
    score += enemiesDefeated * 3;
    score += accuracy / 5;

    // Remove points for struggling
    score -= healthLost / 4;
    score -= damageTaken / 5;
    score -= healingUsed * 6;

    // Keep score in range
    if (score < 0) {
        score = 0;
    }
    if (score > 100) {
        score = 100;
    }

    return score;
}

// Returns spawn change based on score
string adjustSpawns(int challengeScore) {
    if (challengeScore >= 70) {
        return "Increase enemy count, strength, and spawn speed.";
    }
    else if (challengeScore <= 35) {
        return "Reduce enemy count, increase distance, and slow waves.";
    }
    else {
        return "Keep difficulty stable.";
    }
}

// Runs one test case
void runTest(string playerType, int healthLost, int damageTaken, int accuracy,
             int enemiesDefeated, int healingUsed, string expected) {
    int score = calculateChallengeScore(healthLost, damageTaken, accuracy,
                                        enemiesDefeated, healingUsed);

    string actual = adjustSpawns(score);

    cout << playerType << endl;
    cout << "Input: healthLost=" << healthLost
         << ", damageTaken=" << damageTaken
         << ", accuracy=" << accuracy
         << ", enemiesDefeated=" << enemiesDefeated
         << ", healingUsed=" << healingUsed << endl;
    cout << "Challenge Score: " << score << endl;
    cout << "Expected: " << expected << endl;
    cout << "Actual: " << actual << endl;
    cout << endl;
}

int main() {
    runTest("Skilled Player", 20, 30, 75, 12, 1,
            "Increase enemy count, strength, and spawn speed.");

    runTest("Struggling Player", 90, 120, 30, 2, 5,
            "Reduce enemy count, increase distance, and slow waves.");

    runTest("Average Player", 40, 50, 55, 6, 2,
            "Keep difficulty stable.");

    return 0;
}
}
