
In this part of my Git learning journey, I focused on setting up a new Git repository for my project. Here's what I did step by step:

1. **Navigating to the Project Directory**: First, I opened my terminal and navigated to the directory where I wanted to initialize the Git repository. The path was `E:/Mastering Embedded System Learn In Depth/git/RepoTest`. This is where I plan to manage my project files and track changes using Git.

2. **Checking the Current Directory**: To make sure I was in the right place, I used the `pwd` command. This command stands for "print working directory," and it confirmed that I was indeed in the correct folder: `E:/Mastering Embedded System Learn In Depth/git/RepoTest`.

3. **Initializing the Git Repository**: Next, I ran the `git init` command. This command initializes a new Git repository in the current directory. After running it, I saw a message saying, "Initialized empty Git repository in E:/Mastering Embedded System Learn In Depth/git/RepoTest/.git/". This means that Git has set up all the necessary files and folders to start tracking changes in this directory. Specifically, it created a hidden folder named `.git` inside the `RepoTest` directory. This `.git` folder contains all the metadata and version control information that Git needs to manage the repository.

4. **Repository Status**: After initializing the repository, I noticed that my terminal prompt changed. It now shows `(master)` at the end, indicating that I'm working in the default branch of the repository, which is typically called `master`. This is where all my commits will go unless I create or switch to another branch.

---
![Screenshot 2025-03-13 204356](https://github.com/user-attachments/assets/688769cb-1de2-4a34-a0b1-ec62efc969de)
---
5. **Configuring the Repository as Bare**: Next, I ran the command `git config core.bare true`. This command changes the configuration of the repository to make it a "bare" repository. A bare repository is a special type of Git repository that doesn’t have a working directory. Instead, it only contains the version control information (essentially, the contents of the `.git` folder) and no actual working files. Bare repositories are typically used as central repositories for sharing and collaboration, often serving as remote repositories where team members can push and pull changes. By setting this configuration, I prepared the repository for scenarios where it might act as a shared or remote repository, which is especially useful in collaborative projects.
---
![Screenshot 2025-03-13 204725](https://github.com/user-attachments/assets/123309c6-b266-4307-a1de-2efaf95a5c05)
---
