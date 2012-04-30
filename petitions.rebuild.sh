#!/bin/bash
echo "Rebuilding Petitions..."
#rm -Rf modules/contrib themes/ libraries
drush -y make --contrib-destination=./sites/all/ build-petitions.make