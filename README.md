# Adaptive-Balancing

Karlo Tambot — CS 460 Final Project

An adaptive enemy spawn balancing algorithm for video games. The algorithm calculates a challenge score from player performance data, then adjusts enemy spawns so the game stays challenging without becoming unfair.

## How it works

The algorithm uses five gameplay inputs:

- health lost
- damage taken
- accuracy
- enemies defeated
- healing items used

It starts with a balanced score of `50`.

Good performance increases the score:

- more enemies defeated
- higher accuracy

Struggling lowers the score:

- more health lost
- more damage taken
- more healing items used

The final challenge score is kept between `0` and `100`.

- `score >= 70` → increase enemy count, strength, and spawn speed
- `score <= 35` → reduce enemy count, increase distance, and slow waves
- otherwise → keep difficulty stable

## Compile and run

Using a C++ compiler:

```bash
g++ main.cpp -o main
./main
```

## Sample output

```text
Skilled Player
Input: healthLost=20, damageTaken=30, accuracy=75, enemiesDefeated=12, healingUsed=1
Challenge Score: 84
Expected: Increase enemy count, strength, and spawn speed.
Actual: Increase enemy count, strength, and spawn speed.

Struggling Player
Input: healthLost=90, damageTaken=120, accuracy=30, enemiesDefeated=2, healingUsed=5
Challenge Score: 0
Expected: Reduce enemy count, increase distance, and slow waves.
Actual: Reduce enemy count, increase distance, and slow waves.

Average Player
Input: healthLost=40, damageTaken=50, accuracy=55, enemiesDefeated=6, healingUsed=2
Challenge Score: 47
Expected: Keep difficulty stable.
Actual: Keep difficulty stable.
```

## Validation

The program includes three non-trivial test cases: skilled, struggling, and average player. Each test compares the expected difficulty adjustment with the actual output. All three cases match the expected result.

## Complexity

Time: `O(1)` per update because the algorithm uses a fixed number of inputs.  
Space: `O(1)` because it only stores a few variables and the challenge score.

## Files

- `main.cpp` — challenge score calculation, spawn adjustment, and test cases
- `README.md` — project explanation and run instructions

## Future work

Future improvements include adding smoothing difficulty, testing more player types, and connecting the algorithm to a real game environment.
