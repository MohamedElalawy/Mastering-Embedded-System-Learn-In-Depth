## Introduction  

This file contains my notes from the **Version Control Systems (VCS) lecture** in the **Mastering Embedded System Diploma by Learn In Depth**.  

In this lecture, we explored the fundamentals of version control, with a strong focus on **Git**. The notes include **screenshots from our practice sessions** along with **explanations** of key commands and concepts. From initializing repositories to branching, merging, and handling commits, these notes serve as a structured reference for working with Git efficiently.  

setting up a new Git repository for my project. Here's what I did step by step:

1. **Navigating to the Project Directory**: First, I opened my terminal and navigated to the directory where I wanted to initialize the Git repository. The path was `E:/Mastering Embedded System Learn In Depth/git/RepoTest`. This is where I plan to manage my project files and track changes using Git.

2. **Checking the Current Directory**: To make sure I was in the right place, I used the `pwd` command. This command stands for "print working directory," and it confirmed that I was indeed in the correct folder: `E:/Mastering Embedded System Learn In Depth/git/RepoTest`.

3. **Initializing the Git Repository**: Next, I ran the `git init` command. This command initializes a new Git repository in the current directory. After running it, I saw a message saying, "Initialized empty Git repository in E:/Mastering Embedded System Learn In Depth/git/RepoTest/.git/". This means that Git has set up all the necessary files and folders to start tracking changes in this directory. Specifically, it created a hidden folder named `.git` inside the `RepoTest` directory. This `.git` folder contains all the metadata and version control information that Git needs to manage the repository.

4. **Repository Status**: After initializing the repository, I noticed that my terminal prompt changed. It now shows `(master)` at the end, indicating that I'm working in the default branch of the repository, which is typically called `master`. This is where all my commits will go unless I create or switch to another branch.
![Screenshot 2025-03-13 204356](https://github.com/user-attachments/assets/688769cb-1de2-4a34-a0b1-ec62efc969de)
---
5. **Configuring the Repository as Bare**: Next, I ran the command `git config core.bare true`. This command changes the configuration of the repository to make it a "bare" repository. A bare repository is a special type of Git repository that doesn’t have a working directory. Instead, it only contains the version control information (essentially, the contents of the `.git` folder) and no actual working files. Bare repositories are typically used as central repositories for sharing and collaboration, often serving as remote repositories where team members can push and pull changes. By setting this configuration, I prepared the repository for scenarios where it might act as a shared or remote repository, which is especially useful in collaborative projects.
![Screenshot 2025-03-13 204725](https://github.com/user-attachments/assets/123309c6-b266-4307-a1de-2efaf95a5c05)
---
Next, I created a working directory and cloned a repository into it. Here's what I did step by step:

6. **Creating a Working Directory**: I started by navigating to a new directory called `WorkingDirectoryTest` located at `E:/Mastering_Embedded_System_Learn_in_Depth/git/WorkingDirectoryTest`. This directory is where I planned to work on my project and clone an existing repository.

7. **Checking the Current Directory**: To ensure I was in the correct location, I used the `pwd` command. The output confirmed that I was in the right directory: `/e/Mastering_Embedded_System_Learn_in_Depth/git/WorkingDirectoryTest`.

8. **Cloning the Repository**: Next, I cloned an existing repository into this working directory using the `git clone` command. The repository I cloned was located at `/e/Mastering_Embedded_System_Learn_in_Depth/git/RepoTest`. The command I used was:
   ```
   git clone /e/Mastering_Embedded_System_Learn_in_Depth/git/RepoTest
   ```
   After running this command, Git created a new directory named `RepoTest` inside my working directory and cloned the repository into it.

9. **Empty Repository Warning**: During the cloning process, I received a warning: "Warning: You appear to have cloned an empty repository." This message indicates that the repository I cloned doesn’t contain any commits or files yet. It’s essentially an empty repository, which is fine since I can now start adding files and making commits to it.
![Screenshot 2025-03-13 205857](https://github.com/user-attachments/assets/02256889-2d83-4aa4-9f12-2bf7596fb07e)
---
10. **Creating a README File**: After cloning the repository, I decided to add a simple text file to the project. I used the `echo` command to create a file named `README.txt` with the content "Hellooo". The command I used was:
   ```
   echo "Hellooo" > README.txt
   ```
   This command created the README.txt file in the WorkingDirectoryTest directory and added the text "Hellooo" to it. This file can serve as a starting point for 
documenting the project.

![Screenshot 2025-03-13 210635](https://github.com/user-attachments/assets/f36d8852-3fdb-4e04-b88d-aaaa7918bf29)
---
11. **Staging the Changes**: I used the `git add` command to add the updated `README.txt` file to the staging area. The command I ran was:
   ```
   git add README.txt
   ```
   During this step, I received a warning about line endings: "warning: in the working copy of 'README.txt', LF will be replaced by CRLF the next time Git touches it." This warning is related to how Git handles line endings between different operating systems. It’s a common message and doesn’t affect the functionality of the file.

12. **Committing the Changes**: Once the changes were staged, I committed them to the repository using the `git commit` command. I provided a commit message to describe the changes. The command I used was:
   ```
   git commit -m 'README.txt' README.txt
   ```
This committed the changes to the repository with the message "README.txt". The same line-ending warning appeared again during the commit, but it didn’t interfere with the process.

![Screenshot 2025-03-13 220444](https://github.com/user-attachments/assets/4b6855ea-ad34-4304-8953-099d1b08535a)
---
13. **Pushing Changes to the Repository**: After committing the changes locally, I pushed them to the remote repository using the git push command. This command uploads my local commits to the remote repository, making the changes available to others who might be collaborating on the project. The output of the git push command showed that the objects were enumerated, compressed, and written successfully. It also indicated that a new branch, master, was created and pushed to the remote repository located at E:/Mastering_Embedded_System_Learn_In_Depth/git/RepoTest.
    
![Screenshot 2025-03-13 220922](https://github.com/user-attachments/assets/e71f1ee8-bcb8-485c-b249-1730d1b9027c)
---
In this part of my Git workflow, I used the `gitk` command to visualize the commit history of my repository. Here's what I did and observed:

14. **Launching Gitk**: I ran the `gitk` command in my terminal. This command opens a graphical interface that displays the commit history of the repository. It’s a useful tool for visualizing the changes, branches, and commits in a more intuitive way compared to the command line.

15. **Viewing Commit History**: The `gitk` interface showed a detailed history of commits, including the most recent commit I made to the `README.txt` file. Each commit was displayed with its unique hash, author, date, and commit message. This made it easy to see the progression of changes in the repository.

16. **Inspecting Specific Commits**: I could click on individual commits to see more details, such as the changes made in each commit. For example, I was able to see the modifications to the `README.txt` file, including the insertion and deletion of lines. This level of detail is helpful for understanding the evolution of the project and tracking specific changes.

17. **Understanding the Workflow**: Using `gitk` gave me a clearer picture of how my commits are structured and how they relate to each other. It’s a great way to review the history of the repository, especially when working on larger projects with multiple contributors.
    
![Screenshot 2025-03-13 221430](https://github.com/user-attachments/assets/506752e8-c7c8-4828-a520-3ca545aeaf8a)
---
In this part of my Git workflow, I focused on creating and switching to a new branch in my repository. By following these steps, I successfully created and switched to a new branch in my repository. This is an important part of the Git workflow, as it allows me to work on different tasks or features in isolation. Using branches helps keep the main codebase stable while I develop and test new changes. It’s a great way to manage my work and ensure that everything is organized and under control!

18. **Checking Repository Status**: I started by ensuring that my repository was up to date. I used the `git pull` command to fetch any changes from the remote repository and merge them into my local branch. The output indicated that my repository was already up to date, meaning there were no new changes to pull.

19. **Creating and Switching to a New Branch**: Next, I decided to create a new branch to work on. I used the `git checkout` command with the `-b` option to create and switch to a new branch named `my_branch`. The command I ran was:
   ```
   git checkout -b my_branch
   ```
   This command created the new branch and immediately switched to it. The terminal prompt updated to reflect that I was now on the `my_branch` branch.

20. **Repository Status**: After switching to the new branch, my terminal prompt showed `(my_branch)`, confirming that I was now working in the newly created branch. This allows me to make changes and commits without affecting the `master` branch, which is useful for developing new features or experimenting with changes.

![Screenshot 2025-03-13 225523](https://github.com/user-attachments/assets/8b00ff92-e07d-4a61-8f08-20cdf47833e9)
---
21. **Creating a New File in the Branch**: To make some changes specific to this branch, I created a new file named `my_branch_readme.txt`. I used the `echo` command to add the text "hili from my awesome branch" to the file. The command I used was:
   ```
   echo "hili from my awesome branch" > my_branch_readme.txt
   ```
   This command created the file and added the specified text to it. This file is now part of my branch and can be committed to the repository.

![Screenshot 2025-03-13 225841](https://github.com/user-attachments/assets/1e2d28a4-c2b1-4da6-8a4d-bd7e08c66f77)
---

22. **Staging the New File**: After creating the `my_branch_readme.txt` file in the `my_branch` branch, I needed to stage it for commit. I used the `git add` command to add the file to the staging area. The command I ran was:
   ```
   git add my_branch_readme.txt
   ```
   This prepares the file to be included in the next commit.

23. **Committing the Changes**: After staging the `my_branch_readme.txt` file, I proceeded to commit the changes to the repository. I used the `git commit` command with a message describing the update. The command I ran was:
   ```
   git commit -m "adding a readme file to mybranch" my_branch_readme.txt
   ```
   This command commits the changes with the message "adding a readme file to mybranch," which helps document the purpose of the commit.

24. **Commit Confirmation**: The output of the commit command confirmed that the commit was successful. It showed that one file was changed with one insertion, and the file `my_branch_readme.txt` was created with the mode `100644`, which is the standard file permission for a non-executable file in Git.

![Screenshot 2025-03-13 230121](https://github.com/user-attachments/assets/8f163bd1-a525-4550-9ec4-966e5e57d4f8)
---

25. **Pushing the Branch**: After committing the changes to the `my_branch` branch locally, I wanted to share these changes with the remote repository. I used the `git push` command to upload my branch to the remote repository. The command I ran was:
   ```
   git push origin my_branch
   ```
   This command pushes the `my_branch` branch to the remote repository named `origin`.

26. **Upload Process**: The output of the `git push` command showed the progress of uploading the changes. It enumerated and counted the objects, compressed them, and wrote them to the remote repository. The process was completed successfully, and the output indicated that the `my_branch` branch was created on the remote repository.

27. **New Branch Confirmation**: The final message confirmed that the `my_branch` branch was successfully pushed to the remote repository:
   ```
   * [new branch] my_branch -> my_branch
   ```
   This means that the branch is now available remotely, and others can access it if needed.
![Screenshot 2025-03-13 230308](https://github.com/user-attachments/assets/80201941-6df7-43d3-938a-968951ef8dac)
---

28. **Launching Gitk**: I ran the `gitk` command in my terminal to open the graphical interface that displays the commit history of my repository. This tool provides a visual representation of the commits, branches, and changes, making it easier to understand the project's history.

29. **Viewing Commit History**: In the `gitk` interface, I could see the commit history of both the `master` branch and the `my_branch` branch. The most recent commit in `my_branch` was highlighted, with the commit message "adding a readme file to mybranch." This commit was created when I added the `my_branch_readme.txt` file to the branch.

30. **Inspecting the Commit**: I clicked on the commit to see more details about it. The interface showed the changes made in that commit, including the creation of the `my_branch_readme.txt` file. The file was marked as a new file with the mode `100644`, which is the standard permission for a non-executable file in Git. The content of the file, "hili from my awesome branch," was also displayed, showing the exact changes made.

31. **Comparing Branches**: The `gitk` interface allowed me to compare the `my_branch` branch with the `master` branch. I could see that the `my_branch` branch had an additional commit that wasn't present in `master`, reflecting the changes I made specifically in this branch.

![Screenshot 2025-03-13 230411](https://github.com/user-attachments/assets/68dd312f-8947-41a4-81ba-af960d801259)
---

32. **Viewing Commit History**: I ran the `git log` command in my terminal to display the commit history of the repository. This command shows a list of all the commits in the current branch, along with details like the commit hash, author, date, and commit message.

33. **Recent Commits**: The output of `git log` showed the most recent commits in the `my_branch` branch. The latest commit had the message "adding a readme file to mybranch," which corresponds to the changes I made when I added the `my_branch_readme.txt` file. The commit hash for this was `91dc240109dalee48c85c7ddb9f72d89519f775d66`.

34. **Previous Commits**: Below the most recent commit, I could see earlier commits in the repository. One of them was the commit with the message "README.txt," which was made in the `master` branch. This commit had the hash `f952fp3553425c136758a453e5444f192079fd1`. Another commit with the same message but a different hash (`42b1809cb1c8d4bbd64414lb56014604f98f13d2`) was also listed, indicating earlier changes to the `README.txt` file.

35. **Branch Information**: The `git log` output also showed the branch pointers. The `HEAD` pointer was on the `my_branch` branch, and the `origin/my_branch` and `origin/master` branches were also referenced, indicating the state of the remote repository.

![Screenshot 2025-03-13 230932](https://github.com/user-attachments/assets/ae71e99b-2d14-414a-ac47-4e7a9fffeee4)
---
In this part, I intentionally made an undesired change to the `my_branch_readme.txt` file and committed it. Here's what I did and what I plan to do next:

36. **Editing the File**: I opened the `my_branch_readme.txt` file using the `vi` text editor. I made some changes to the file, which I later realized were incorrect or undesired.

37. **Committing the Changes**: After making the changes, I staged and committed them using the following commands:
   ```
   git commit -m "ruining the code by mistake" my_branch_readme.txt
   ```
   The commit message "ruining the code by mistake" indicates that I recognized the changes were not what I intended. During the commit, I received warnings about line endings being replaced, which is a common Git behavior to ensure consistency across different operating systems.
In this part of my Git workflow, I pushed the undesired change I made earlier to the remote repository. Here's what I did:

38. **Pushing the Undesired Change**: After committing the incorrect changes to the `my_branch_readme.txt` file, I pushed these changes to the remote repository using the `git push` command. The command I ran was:
   ```
   git push origin my_branch
   ```
   This command uploaded the latest commit, which included the undesired changes, to the `my_branch` branch on the remote repository.
In this part of my Git workflow, I took steps to revert to the correct version of my repository after pushing an undesired change. Here's what I did:

39. **Using Gitk to Visualize Commits**: I ran the `gitk` command to open the graphical interface that displays the commit history of my repository. This tool allowed me to visually inspect the commits and identify the correct version I wanted to revert to. In this case, I was looking for the commit before the undesired change was made.

40. **Identifying the Correct Commit**: In the `gitk` interface, I located the commit with the hash `91dc240109dale48c85c7ddb9f7d89519f775d66`. This was the commit where the `my_branch_readme.txt` file was correctly added with the message "adding a readme file to mybranch." This is the version I wanted to restore.

41. **Switching to the Correct Commit**: I used the `git checkout` command to switch to the correct commit. The command I ran was:
   ```
   git checkout 91dc240109dale48c85c7ddb9f7d89519f775d66
   ```
   This command moved the `HEAD` pointer to the specified commit, effectively putting me in a "detached HEAD" state. In this state, I can inspect the repository as it was at that commit without affecting any branches.

42. **Detached HEAD State**: The terminal output explained that I was in a "detached HEAD" state. This means I can look around, make experimental changes, and even create new commits if I want. However, these changes won’t affect any existing branches unless I create a new branch to retain them. If I don’t need to keep any changes, I can simply switch back to a branch later.

![Screenshot 2025-03-13 232303](https://github.com/user-attachments/assets/40ace3a6-61c3-4567-a308-29390e982097)
---
In this part,  I took steps to fix the corrupted version of the `my_branch_readme.txt` file by copying the correct version from a previous commit. Here's what I did:

43. **Copying the Correct File**: While in the detached HEAD state (at the commit `91dc240109dale48c85c7ddb9f7d89519f775d66`), I copied the correct version of the `my_branch_readme.txt` file to a temporary location. The command I used was:
   ```
   cp my_branch_readme.txt .../
   ```
   This command copied the file to a directory outside the repository, ensuring I could access it after switching branches.

44. **Switching Back to the Corrupted Branch**: After copying the correct file, I switched back to the `my_branch` branch using the `git checkout` command:
   ```
   git checkout my_branch
   ```
   This command moved me back to the `my_branch` branch, where the corrupted version of the file was present.

45. **Next Steps**: Now that I have the correct version of the file saved, I plan to paste it back into the `my_branch` directory to replace the corrupted version. This will effectively restore the file to its correct state.


46. **Pasting the Correct File**: I copied the correct version of the `my_branch_readme.txt` file from the temporary location back into the `my_branch` directory. The command I used was:
   ```
   cp .../my_branch_readme.txt .
   ```
   This command replaced the corrupted version of the file in the `my_branch` directory with the correct version I had saved earlier.

47. **Committing the Fix**: After pasting the correct file, I staged and committed the change to the repository. The command I ran was:
   ```
   git commit -m "reversing last commit to solve bug" my_branch_readme.txt
   ```
   The commit message "reversing last commit to solve bug" indicates that this commit is intended to fix the issue caused by the previous undesired change. The output showed that one file was changed with one deletion, reflecting the correction made to the file.
In this part of my Git workflow, I attempted to push the fixed changes to the remote repository. Here's what I did:

48. **Pushing the Fix**: After committing the corrected version of the `my_branch_readme.txt` file, I wanted to push these changes to the remote repository. I used the `git push` command to upload the changes. The command I ran was:
   ```
   git push origin my_branch
   ```
   This command is intended to push the changes from my local `my_branch` branch to the remote `my_branch` branch.
![Screenshot 2025-03-13 233323](https://github.com/user-attachments/assets/8ff51391-4f37-42dd-ad85-7924adfc7da4)
---
![Screenshot 2025-03-13 233556](https://github.com/user-attachments/assets/6893e1f7-3142-4bc3-85fb-d817d0bdad23)
---
49. I successfully merged my branch `my_branch` into `master`. First, I checked the differences between the two branches using `git diff my_branch master`, which showed that `my_branch_readme.txt` was missing in `master`.  

To resolve this, I switched to `master` using `git checkout master`, ensuring it was up to date. Then, I merged `my_branch` into `master` using a fast-forward merge with `git merge my_branch`, which restored `my_branch_readme.txt` in `master`.  

Now, my changes are integrated, and `master` contains the file from `my_branch`. 
![Screenshot 2025-03-14 001333](https://github.com/user-attachments/assets/717d8019-c846-42c4-9d8e-a06d07bbfce9)
