$Id$

Copyright 2010 Matthew Dorman

Description
-----------
This module allows for site owners to utilize a shared cache and CDN
for all core JavaScript files. By serving these shared files from a 
single domain and CDN end users will gain significant caching as they 
go from one Drupal site to another. In addition, the shared domain will 
serve the files from a CDN to geographically locate the responses from 
a server nearby.

Important to note, this module utilizes the j.cmscdn.net domain so that 
you do not have to maintain your own. This module only requires you to 
download and enable it to take advantage of a CDN for a number of files.

Features
--------
* Serves the jquery file from a googleapis domain for even more likelyhood
  of end users having a cached version.

Database
--------
This module does not require any new database tables to be installed.

Installation:
-------------

1. Copy the cmscdn.module to the Drupal modules/ directory.

2. Go to Administer -> Build -> Modules
   - Enable the cmscdn module, click on Save

5. Test your site pages.
   - All pages should render as they did before.
   - View Source, if you do not see references to cdncms.com clear cache.
   - Log out from your site.
   - All pages should still render as they did before.

Bugs/Features/Patches
---------------------
If you want to report bugs, feature requests, or submit a patch, please do so
at the project page on the Drupal web site.
http://drupal.org/project/URL_TO_COME_ONCE_APPROVED

Author
------

Matthew Dorman (@matthewdorman)

If you use this module, find it useful, and want to send the author
a thank you note, then send the author a message, or update the project page.

