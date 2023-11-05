"use strict";(self.webpackChunkcsposts=self.webpackChunkcsposts||[]).push([[8766],{7422:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>o,contentTitle:()=>r,default:()=>h,frontMatter:()=>l,metadata:()=>i,toc:()=>c});var s=n(5893),a=n(1151);const l={},r=void 0,i={id:"DSA/Last Moment Before All Ants Fall Out of a Plank",title:"Last Moment Before All Ants Fall Out of a Plank",description:"Intuition: It doesn\u2019t matter when the ants change directions given all of them are going in the same speed.",source:"@site/docs/DSA/1503. Last Moment Before All Ants Fall Out of a Plank.md",sourceDirName:"DSA",slug:"/DSA/Last Moment Before All Ants Fall Out of a Plank",permalink:"/docs/DSA/Last Moment Before All Ants Fall Out of a Plank",draft:!1,unlisted:!1,editUrl:"https://github.com/facebook/docusaurus/tree/main/packages/create-docusaurus/templates/shared/docs/DSA/1503. Last Moment Before All Ants Fall Out of a Plank.md",tags:[],version:"current",sidebarPosition:1503,frontMatter:{},sidebar:"tutorialSidebar",previous:{title:"Translate your site",permalink:"/docs/tutorial-extras/translate-your-site"}},o={},c=[];function m(e){const t={annotation:"annotation",code:"code",math:"math",mi:"mi",mn:"mn",mo:"mo",mrow:"mrow",p:"p",pre:"pre",semantics:"semantics",span:"span",...(0,a.a)(),...e.components};return(0,s.jsxs)(s.Fragment,{children:[(0,s.jsx)(t.p,{children:"Intuition: It doesn\u2019t matter when the ants change directions given all of them are going in the same speed."}),"\n",(0,s.jsxs)(t.p,{children:["Time Complexity: ",(0,s.jsxs)(t.span,{className:"katex",children:[(0,s.jsx)(t.span,{className:"katex-mathml",children:(0,s.jsx)(t.math,{xmlns:"http://www.w3.org/1998/Math/MathML",children:(0,s.jsxs)(t.semantics,{children:[(0,s.jsxs)(t.mrow,{children:[(0,s.jsx)(t.mi,{children:"O"}),(0,s.jsx)(t.mo,{stretchy:"false",children:"("}),(0,s.jsx)(t.mi,{children:"n"}),(0,s.jsx)(t.mo,{stretchy:"false",children:")"})]}),(0,s.jsx)(t.annotation,{encoding:"application/x-tex",children:"O(n)"})]})})}),(0,s.jsx)(t.span,{className:"katex-html","aria-hidden":"true",children:(0,s.jsxs)(t.span,{className:"base",children:[(0,s.jsx)(t.span,{className:"strut",style:{height:"1em",verticalAlign:"-0.25em"}}),(0,s.jsx)(t.span,{className:"mord mathnormal",style:{marginRight:"0.02778em"},children:"O"}),(0,s.jsx)(t.span,{className:"mopen",children:"("}),(0,s.jsx)(t.span,{className:"mord mathnormal",children:"n"}),(0,s.jsx)(t.span,{className:"mclose",children:")"})]})})]})]}),"\n",(0,s.jsxs)(t.p,{children:["Space Complexity: ",(0,s.jsxs)(t.span,{className:"katex",children:[(0,s.jsx)(t.span,{className:"katex-mathml",children:(0,s.jsx)(t.math,{xmlns:"http://www.w3.org/1998/Math/MathML",children:(0,s.jsxs)(t.semantics,{children:[(0,s.jsxs)(t.mrow,{children:[(0,s.jsx)(t.mi,{children:"O"}),(0,s.jsx)(t.mo,{stretchy:"false",children:"("}),(0,s.jsx)(t.mn,{children:"1"}),(0,s.jsx)(t.mo,{stretchy:"false",children:")"})]}),(0,s.jsx)(t.annotation,{encoding:"application/x-tex",children:"O(1)"})]})})}),(0,s.jsx)(t.span,{className:"katex-html","aria-hidden":"true",children:(0,s.jsxs)(t.span,{className:"base",children:[(0,s.jsx)(t.span,{className:"strut",style:{height:"1em",verticalAlign:"-0.25em"}}),(0,s.jsx)(t.span,{className:"mord mathnormal",style:{marginRight:"0.02778em"},children:"O"}),(0,s.jsx)(t.span,{className:"mopen",children:"("}),(0,s.jsx)(t.span,{className:"mord",children:"1"}),(0,s.jsx)(t.span,{className:"mclose",children:")"})]})})]})]}),"\n",(0,s.jsx)(t.pre,{children:(0,s.jsx)(t.code,{className:"language-cpp",children:"class Solution {\npublic:\n    int getLastMoment(int n, vector<int>& left, vector<int>& right) {\n        const int lastMomentForLeft = left.empty() ? 0 : *max_element(left.begin(), left.end());\n        const int lastMomentForRight = right.empty() ? 0 : (n - *min_element(right.begin(), right.end()));\n\n        return max(lastMomentForLeft, lastMomentForRight);\n    }\n};\n"})})]})}function h(e={}){const{wrapper:t}={...(0,a.a)(),...e.components};return t?(0,s.jsx)(t,{...e,children:(0,s.jsx)(m,{...e})}):m(e)}},1151:(e,t,n)=>{n.d(t,{Z:()=>i,a:()=>r});var s=n(7294);const a={},l=s.createContext(a);function r(e){const t=s.useContext(l);return s.useMemo((function(){return"function"==typeof e?e(t):{...t,...e}}),[t,e])}function i(e){let t;return t=e.disableParentContext?"function"==typeof e.components?e.components(a):e.components||a:r(e.components),s.createElement(l.Provider,{value:t},e.children)}}}]);