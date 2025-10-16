# Git commands

## Git diff
git diff "here is the first hash" "and the second hash"

## Git log

To get the hash use:
```
git log 
```

sample 
commit 1a935a0d700b6ce93ead02473ae19ee826c555ed (HEAD -> main, origin/main)
//     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//     this is the hash (you just need to give the first few digits, as long as it doesn't conflict)

   e.g. 1a9356 and 1a9357 will conflict if you give only 1a93
        ^^^^       ^^^^                                   |
        |          |                                      |
        +----------+--------------------------------------+

ctrl h helps me replace stuff faster yay.

## Git blame

git blame "put filename here"

This lets you know who last changed each line in a file.

## Git tutorial

to open the tutorial page:
on linux, type:

man gittutorial