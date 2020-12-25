import React from "react"
import { useStaticQuery, graphql } from "gatsby"


const TelegramComments = () => {
    const telegramSiteIdQuery = useStaticQuery(
        graphql`
          query {
            site {
              siteMetadata {
                telegramSiteId
              }
            }
          }
        `
    )

    const telegramSiteId = telegramSiteIdQuery.site.siteMetadata.telegramSiteId;

    return (
        <script async src="https://comments.app/js/widget.js?3" data-comments-app-website={ telegramSiteId } data-limit="100"></script>
    )
}

export default TelegramComments
