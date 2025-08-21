# StackOverFlow

Design and implement a simplified StackOverflow-like Q&A platform. The system should allow users to post questions and answers, vote on them, comment, tag questions, and track user reputation.

## Problem Statement

Design and implement a simplified StackOverflow-like Q&A platform. The system should allow users to post questions and answers, vote on them, comment, tag questions, and track user reputation.

---

## Requirements

-   **User Management**: Users can ask questions, answer, comment, and vote.
-   **Questions & Answers**: Users can post questions and answers. Each question can have multiple answers, and one accepted answer.
-   **Voting**: Users can upvote or downvote questions and answers. Reputation is updated accordingly.
-   **Comments**: Users can comment on both questions and answers.
-   **Tags**: Questions can be tagged for categorization.
-   **Reputation**: Users gain or lose reputation based on votes and accepted answers.
-   **Accepted Answer**: The question author can mark one answer as accepted.

---

## Commits

1.  **Initial commit**

2.  **[FEAT] : adds user header and implementation**
    -   **methods**:
        -   getters: `getName`, `getUserId`, `getEmail`, `getReputation` (*all getters are `const`, they won't change member variables*).
        -   other: `updateReputation`.
    -   **member variables**: `userId`, `name`, `email`, `reputation`.

3.  **[FEAT] : adds tag header and implementation**
    -   **methods**:
        -   getters: `getName`, `getId`.
    -   **member variables**: `id`, `name`.

4.  **[FEAT] : adds vote header and implementation**
    -   **methods**:
        -   getters: `getUser`, `getType`.
    -   **variables**:
        -   `voter` (`&User`), `type` (`VoteType`).

5.  **[FEAT] : adds types enum for votes and reputations**
    -   `enum class` for `VoteType` and `ReputationType`.
    -   Helper functions to convert types into integer references.

6.  **[FEAT] : adds comment header and implementation**
    -   **methods**:
        -   getters: `getId`, `getAuthor`, `getContent`.
    -   **variables**: `contents`, `author` (`&User`), `creation_time` (chrono object), `id`.

7.  **[FEAT] : adds commentable and votable abstract base classes**
    -   **methods for `Commentable` abstract class**: `addComment`, `getComments`.
    -   **methods for `Votable` abstract class**: `vote`, `getVoteCount`.