At first:

git config --global core.compression 0

then, clone just a part of your repo:

git clone --depth 1 <repo_URI>




==========================================
a partir daq n entendi

and now "the rest"

git fetch --unshallow

but here is the trick.: When you have a big repo sometimes you must perform that step multiple times. So... again,

git fetch --unshallow

and so on.

Try multiple times. Probably you will see, that each time you perform 'unshallow' you get more and more objects before the error.

And at the end, just to be sure.

git pull --all
